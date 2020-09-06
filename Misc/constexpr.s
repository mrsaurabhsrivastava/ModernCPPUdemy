	.file	"constexpr.cpp"
	.intel_syntax noprefix
# GNU C++14 (Ubuntu 7.5.0-3ubuntu1~18.04) version 7.5.0 (x86_64-linux-gnu)
#	compiled by GNU C version 7.5.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.19-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE constexpr.cpp
# -masm=intel -mtune=generic -march=x86-64 -fverbose-asm
# -fstack-protector-strong -Wformat -Wformat-security
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fexceptions -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm
# -fgnu-runtime -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
# -fplt -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fssa-backprop -fstack-protector-strong
# -fstdarg-opt -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
# -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
# -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
# -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
# -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	_Z3Addii
	.type	_Z3Addii, @function
_Z3Addii:
.LFB1495:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], edi	# x, x
	mov	DWORD PTR -8[rbp], esi	# y, y
# constexpr.cpp:20: 	return x+y;
	mov	edx, DWORD PTR -4[rbp]	# tmp89, x
	mov	eax, DWORD PTR -8[rbp]	# tmp90, y
	add	eax, edx	# _3, tmp89
# constexpr.cpp:21: }
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1495:
	.size	_Z3Addii, .-_Z3Addii
	.globl	main
	.type	main, @function
main:
.LFB1496:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 16	#,
# constexpr.cpp:24: 	const int x = Add(5,6);
	mov	esi, 6	#,
	mov	edi, 5	#,
	call	_Z3Addii	#
	mov	DWORD PTR -4[rbp], eax	# x, tmp89
# constexpr.cpp:25: }
	mov	eax, 0	# _4,
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1496:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1977:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 16	#,
	mov	DWORD PTR -4[rbp], edi	# __initialize_p, __initialize_p
	mov	DWORD PTR -8[rbp], esi	# __priority, __priority
# constexpr.cpp:25: }
	cmp	DWORD PTR -4[rbp], 1	# __initialize_p,
	jne	.L7	#,
# constexpr.cpp:25: }
	cmp	DWORD PTR -8[rbp], 65535	# __priority,
	jne	.L7	#,
# /usr/include/c++/7/iostream:74:   static ios_base::Init __ioinit;
	lea	rdi, _ZStL8__ioinit[rip]	#,
	call	_ZNSt8ios_base4InitC1Ev@PLT	#
	lea	rdx, __dso_handle[rip]	#,
	lea	rsi, _ZStL8__ioinit[rip]	#,
	mov	rax, QWORD PTR _ZNSt8ios_base4InitD1Ev@GOTPCREL[rip]	# tmp87,
	mov	rdi, rax	#, tmp87
	call	__cxa_atexit@PLT	#
.L7:
# constexpr.cpp:25: }
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1977:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z3Addii, @function
_GLOBAL__sub_I__Z3Addii:
.LFB1978:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
# constexpr.cpp:25: }
	mov	esi, 65535	#,
	mov	edi, 1	#,
	call	_Z41__static_initialization_and_destruction_0ii	#
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1978:
	.size	_GLOBAL__sub_I__Z3Addii, .-_GLOBAL__sub_I__Z3Addii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3Addii
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
