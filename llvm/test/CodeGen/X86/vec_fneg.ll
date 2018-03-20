; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -mtriple=i686-unknown-unknown -mattr=+sse  | FileCheck %s --check-prefix=X32-SSE --check-prefix=X32-SSE1
; RUN: llc < %s -mtriple=i686-unknown-unknown -mattr=+sse2 | FileCheck %s --check-prefix=X32-SSE --check-prefix=X32-SSE2
; RUN: llc < %s -mtriple=x86_64-unknown-unknown -mattr=-sse2 | FileCheck %s --check-prefix=X64-SSE --check-prefix=X64-SSE1
; RUN: llc < %s -mtriple=x86_64-unknown-unknown -mattr=+sse2 | FileCheck %s --check-prefix=X64-SSE --check-prefix=X64-SSE2

; FNEG is defined as subtraction from -0.0.

; This test verifies that we use an xor with a constant to flip the sign bits; no subtraction needed.
define <4 x float> @t1(<4 x float> %Q) nounwind {
; X32-SSE-LABEL: t1:
; X32-SSE:       # BB#0:
; X32-SSE-NEXT:    xorps .LCPI0_0, %xmm0
; X32-SSE-NEXT:    retl
;
; X64-SSE-LABEL: t1:
; X64-SSE:       # BB#0:
; X64-SSE-NEXT:    xorps {{.*}}(%rip), %xmm0
; X64-SSE-NEXT:    retq
  %tmp = fsub <4 x float> < float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00 >, %Q
  ret <4 x float> %tmp
}

; This test verifies that we generate an FP subtraction because "0.0 - x" is not an fneg.
define <4 x float> @t2(<4 x float> %Q) nounwind {
; X32-SSE-LABEL: t2:
; X32-SSE:       # BB#0:
; X32-SSE-NEXT:    xorps %xmm1, %xmm1
; X32-SSE-NEXT:    subps %xmm0, %xmm1
; X32-SSE-NEXT:    movaps %xmm1, %xmm0
; X32-SSE-NEXT:    retl
;
; X64-SSE-LABEL: t2:
; X64-SSE:       # BB#0:
; X64-SSE-NEXT:    xorps %xmm1, %xmm1
; X64-SSE-NEXT:    subps %xmm0, %xmm1
; X64-SSE-NEXT:    movaps %xmm1, %xmm0
; X64-SSE-NEXT:    retq
  %tmp = fsub <4 x float> zeroinitializer, %Q
  ret <4 x float> %tmp
}

; If we're bitcasting an integer to an FP vector, we should avoid the FPU/vector unit entirely.
; Make sure that we're flipping the sign bit and only the sign bit of each float.
; So instead of something like this:
;    movd	%rdi, %xmm0
;    xorps	.LCPI2_0(%rip), %xmm0
;
; We should generate:
;    movabsq     (put sign bit mask in integer register))
;    xorq        (flip sign bits)
;    movd        (move to xmm return register)

define <2 x float> @fneg_bitcast(i64 %i) nounwind {
; X32-SSE1-LABEL: fneg_bitcast:
; X32-SSE1:       # BB#0:
; X32-SSE1-NEXT:    pushl %ebp
; X32-SSE1-NEXT:    movl %esp, %ebp
; X32-SSE1-NEXT:    andl $-16, %esp
; X32-SSE1-NEXT:    subl $32, %esp
; X32-SSE1-NEXT:    movl $-2147483648, %eax # imm = 0x80000000
; X32-SSE1-NEXT:    movl 12(%ebp), %ecx
; X32-SSE1-NEXT:    xorl %eax, %ecx
; X32-SSE1-NEXT:    movl %ecx, {{[0-9]+}}(%esp)
; X32-SSE1-NEXT:    xorl 8(%ebp), %eax
; X32-SSE1-NEXT:    movl %eax, (%esp)
; X32-SSE1-NEXT:    movaps (%esp), %xmm0
; X32-SSE1-NEXT:    movl %ebp, %esp
; X32-SSE1-NEXT:    popl %ebp
; X32-SSE1-NEXT:    retl
;
; X32-SSE2-LABEL: fneg_bitcast:
; X32-SSE2:       # BB#0:
; X32-SSE2-NEXT:    movl $-2147483648, %eax # imm = 0x80000000
; X32-SSE2-NEXT:    movl {{[0-9]+}}(%esp), %ecx
; X32-SSE2-NEXT:    xorl %eax, %ecx
; X32-SSE2-NEXT:    movd %ecx, %xmm1
; X32-SSE2-NEXT:    xorl {{[0-9]+}}(%esp), %eax
; X32-SSE2-NEXT:    movd %eax, %xmm0
; X32-SSE2-NEXT:    punpckldq {{.*#+}} xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
; X32-SSE2-NEXT:    retl
;
; X64-SSE1-LABEL: fneg_bitcast:
; X64-SSE1:       # BB#0:
; X64-SSE1-NEXT:    movabsq $-9223372034707292160, %rax # imm = 0x8000000080000000
; X64-SSE1-NEXT:    xorq %rdi, %rax
; X64-SSE1-NEXT:    movq %rax, -{{[0-9]+}}(%rsp)
; X64-SSE1-NEXT:    movaps -{{[0-9]+}}(%rsp), %xmm0
; X64-SSE1-NEXT:    retq
;
; X64-SSE2-LABEL: fneg_bitcast:
; X64-SSE2:       # BB#0:
; X64-SSE2-NEXT:    movabsq $-9223372034707292160, %rax # imm = 0x8000000080000000
; X64-SSE2-NEXT:    xorq %rdi, %rax
; X64-SSE2-NEXT:    movd %rax, %xmm0
; X64-SSE2-NEXT:    retq
  %bitcast = bitcast i64 %i to <2 x float>
  %fneg = fsub <2 x float> <float -0.0, float -0.0>, %bitcast
  ret <2 x float> %fneg
}
