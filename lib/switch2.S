

.syntax unified
#### struct thread *switch_threads (struct thread *cur, struct thread *next);
####
#### Switches from CUR, which must be the running thread, to NEXT,
#### which must also be running switch_threads(), returning CUR in
#### NEXT's context.
####
#### This function works by assuming that the thread we're switching
#### into is also running switch_threads().  Thus, all it has to do is
#### preserve a few registers on the stack, then switch stacks and
#### restore the registers.  As part of switching stacks we record the
#### current stack pointer in CUR's thread structure.

.globl switch_threads
.func switch_threads
switch_threads:
	# Save caller's register state.
	#
	# Note that the SVR4 ABI allows us to destroy %eax, %ecx, %edx,
	# but requires us to preserve %ebx, %ebp, %esi, %edi.  See
	# [SysV-ABI-386] pages 3-11 and 3-12 for details.
	#
	# This stack frame must match the one set up by thread_create()
	# in size.

	# Numeros de registros de https://azeria-labs.com/arm-data-types-and-registers-part-2/
	# pushl %ebx
	push {r1}
	# pushl %ebp
	mov r1, fp
	push {r1}
	# pushl %esi
	push {r4}
	# pushl %edi
	push {r5}

	# Get offsetof (struct thread, stack).
.globl thread_stack_ofs
	# mov thread_stack_ofs, %edx
	movs thread_stack_ofs, R3

	# Save current stack pointer to old thread's stack, if any.
	# movl SWITCH_CUR(%esp), %eax
	ldr r0, SWITCH_CUR(sp)
	# movl %esp, (%eax,%edx,1)
	adds R2, R0, R3      ; R2 = R0 + R3
	str R13, [R2]

	# Restore stack pointer from new thread's stack.
	# movl SWITCH_NEXT(%esp), %ecx
	str r2, SWITCH_NEXT(sp)
	# movl (%ecx,%edx,1), %esp
	adds r4, r2, r3		; R4 = r2 + r3
	ldr sp, [r4]

	# Restore caller's register state.
	# popl %edi
	pop {r5}
	# popl %esi
	pop {r4}
	# popl %ebp
	pop {fp}
	# popl %ebx
	pop {r1}
        ret
.endfunc

.globl switch_entry
.func switch_entry
switch_entry:
	# Discard switch_threads() arguments.
	# addl $8, %esp
	adds sp, sp, #8

	# Call thread_schedule_tail(prev).
	# pushl %eax
	push {r0}
.globl thread_schedule_tail
	# call thread_schedule_tail
	bl thread_schedule_tail
	# addl $4, %esp
	adds sp, sp, #4

	# Start thread proper.
	ret
.endfunc
