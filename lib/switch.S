.syntax unified

# define SWITCH_CUR      20
# define SWITCH_NEXT     24

.global switch_threads
.type switch_threads, %function
switch_threads:
    # Save caller's register state
    PUSH {R3, R5, R6, R7}

    # Get offsetof (struct thread, stack)
.global thread_stack_ofs
    LDR R2, =thread_stack_ofs
    LDR R2, [R2]

    # Save current stack pointer to old thread's stack, if any
    LDR R0, [SP, #20]
    ADDS R1, R0, R2
    MOV R3, SP
    STR R3, [R1]

    # Restore stack pointer from new thread's stack
    LDR R3, [SP, #24]
    ADDS R3, R3, R2
    LDR R3, [R3]
    MOV SP, R3

    # Restore caller's register state
    POP {R3, R5, R6, R7}

    BX LR
.size switch_threads, .-switch_threads

.global switch_entry
.type switch_entry, %function
switch_entry:
    # Discard switch_threads() arguments
    ADD SP, SP, #8

    # Call thread_schedule_tail(prev)
    PUSH {R0}
    BL thread_schedule_tail
    ADD SP, SP, #4

    # Start thread proper
    BX LR
.size switch_entry, .-switch_entry
