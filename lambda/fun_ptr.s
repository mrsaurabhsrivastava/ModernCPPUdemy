	.file	"fun_ptr.cpp"
# GNU C++14 (Ubuntu 7.5.0-3ubuntu1~18.04) version 7.5.0 (x86_64-linux-gnu)
#	compiled by GNU C version 7.5.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.19-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE fun_ptr.cpp
# -mtune=generic -march=x86-64 -O1 -fverbose-asm -fstack-protector-strong
# -Wformat -Wformat-security
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg
# -fchkp-check-incomplete-type -fchkp-check-read -fchkp-check-write
# -fchkp-instrument-calls -fchkp-narrow-bounds -fchkp-optimize
# -fchkp-store-bounds -fchkp-use-static-bounds
# -fchkp-use-static-const-bounds -fchkp-use-wrappers
# -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
# -fdefer-pop -fdelete-null-pointer-checks -fdwarf2-cfi-asm
# -fearly-inlining -feliminate-unused-debug-types -fexceptions
# -fforward-propagate -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm
# -fgnu-runtime -fgnu-unique -fguess-branch-probability -fident
# -fif-conversion -fif-conversion2 -finline -finline-atomics
# -finline-functions-called-once -fipa-profile -fipa-pure-const
# -fipa-reference -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-constants -fmerge-debug-strings -fmove-loop-invariants
# -fomit-frame-pointer -fpeephole -fplt -fprefetch-loop-arrays
# -freg-struct-return -freorder-blocks -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fshrink-wrap
# -fshrink-wrap-separate -fsigned-zeros -fsplit-ivs-in-unroller
# -fsplit-wide-types -fssa-backprop -fssa-phiopt -fstack-protector-strong
# -fstdarg-opt -fstrict-volatile-bitfields -fsync-libcalls
# -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim
# -ftree-dce -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pta
# -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr -ftree-sra
# -ftree-ter -funit-at-a-time -funwind-tables -fverbose-asm
# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.globl	_Z10CompareFunii
	.type	_Z10CompareFunii, @function
_Z10CompareFunii:
.LFB1565:
	.cfi_startproc
# fun_ptr.cpp:42:     return x < y;
	cmpl	%esi, %edi	# y, x
	setl	%al	#, tmp91
# fun_ptr.cpp:43: }
	ret
	.cfi_endproc
.LFE1565:
	.size	_Z10CompareFunii, .-_Z10CompareFunii
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	" "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1567:
	.cfi_startproc
	pushq	%r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$32, %rsp	#,
	.cfi_def_cfa_offset 64
# fun_ptr.cpp:55: {
	movq	%fs:40, %rax	#, tmp129
	movq	%rax, 24(%rsp)	# tmp129, D.41169
	xorl	%eax, %eax	# tmp129
# fun_ptr.cpp:56:     int arr[] = {3,1,5,2,4};
	movl	$3, (%rsp)	#, arr
	movl	$1, 4(%rsp)	#, arr
	movl	$5, 8(%rsp)	#, arr
	movl	$2, 12(%rsp)	#, arr
	movl	$4, 16(%rsp)	#, arr
	movl	$4, %edi	#, ivtmp_24
	jmp	.L6	#
.L5:
	addq	$4, %rax	#, ivtmp.37
# fun_ptr.cpp:28:         for (int j = 0; j < SIZE-1; j++)
	cmpq	%rsi, %rax	# _45, ivtmp.37
	je	.L4	#,
.L3:
# fun_ptr.cpp:30:             if (xFn(xArr[j], xArr[j+1]))
	movl	4(%rax), %edx	# MEM[base: _46, offset: 4B], _20
	movl	(%rax), %ecx	# MEM[base: _46, offset: 0B], _21
	cmpl	%ecx, %edx	# _21, _20
	jle	.L5	#,
# fun_ptr.cpp:33:                 xArr[j+1] = std::move(xArr[j]);
	movl	%ecx, 4(%rax)	# _21, MEM[base: _46, offset: 4B]
# fun_ptr.cpp:34:                 xArr[j] = std::move(lTmp);
	movl	%edx, (%rax)	# _20, MEM[base: _46, offset: 0B]
	jmp	.L5	#
.L4:
# fun_ptr.cpp:26:     for (int i = 0; i < SIZE-1; i++)
	subl	$1, %edi	#, ivtmp_24
	je	.L12	#,
.L6:
	movq	%rsp, %rbx	#, ivtmp.28
	leaq	16(%rbx), %rsi	#, _45
# fun_ptr.cpp:56:     int arr[] = {3,1,5,2,4};
	movq	%rbx, %rax	# ivtmp.28, ivtmp.37
	jmp	.L3	#
.L12:
	leaq	20(%rbx), %r12	#, _17
# fun_ptr.cpp:59:         std::cout<<e<<" ";
	leaq	_ZSt4cout(%rip), %rbp	#, tmp128
.L7:
# fun_ptr.cpp:59:         std::cout<<e<<" ";
	movl	(%rbx), %esi	# MEM[base: _2, offset: 0],
	movq	%rbp, %rdi	# tmp128,
	call	_ZNSolsEi@PLT	#
# /usr/include/c++/7/ostream:561: 	__ostream_insert(__out, __s,
	movl	$1, %edx	#,
	leaq	.LC0(%rip), %rsi	#,
	movq	%rax, %rdi	# _12,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT	#
	addq	$4, %rbx	#, ivtmp.28
# fun_ptr.cpp:58:     for (const auto &e : arr)
	cmpq	%rbx, %r12	# ivtmp.28, _17
	jne	.L7	#,
# /usr/include/c++/7/ostream:113: 	return __pf(*this);
	leaq	_ZSt4cout(%rip), %rdi	#,
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@PLT	#
# fun_ptr.cpp:61: }
	movl	$0, %eax	#,
	movq	24(%rsp), %rdi	# D.41169, tmp130
	xorq	%fs:40, %rdi	#, tmp130
	jne	.L13	#,
	addq	$32, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx	#
	.cfi_def_cfa_offset 24
	popq	%rbp	#
	.cfi_def_cfa_offset 16
	popq	%r12	#
	.cfi_def_cfa_offset 8
	ret
.L13:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
	.cfi_endproc
.LFE1567:
	.size	main, .-main
	.type	_GLOBAL__sub_I__Z10CompareFunii, @function
_GLOBAL__sub_I__Z10CompareFunii:
.LFB2058:
	.cfi_startproc
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 16
# /usr/include/c++/7/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rdi	#,
	call	_ZNSt8ios_base4InitC1Ev@PLT	#
	leaq	__dso_handle(%rip), %rdx	#,
	leaq	_ZStL8__ioinit(%rip), %rsi	#,
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi	#,
	call	__cxa_atexit@PLT	#
# fun_ptr.cpp:61: }
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2058:
	.size	_GLOBAL__sub_I__Z10CompareFunii, .-_GLOBAL__sub_I__Z10CompareFunii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z10CompareFunii
	.globl	obj
	.bss
	.type	obj, @object
	.size	obj, 1
obj:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
