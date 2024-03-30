# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans:
	pushq %rbp			#save the caller's value for %rbp into the callee's stack
	movq  %rsp, %rbp		#save the current stack pointer in %rbp

					# (2) What is going on here
					# Ans:use syscall to print the string to the standard output
	movq $1, %rax			# %rax = 1 (system call for write)
	movq $1, %rdi			# %rdi = 1 (file handle 1 is stdout)
	leaq .hello.str,%rsi		# store the calculated memory offset in the %rsi register


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans:request oerating system to services using sys call instruction.
                                        # Also transfare control to the operating system to request service and return. 
	syscall				# Which syscall is being run?
					# Ans:syscall transfer the conrtol to operation to perform the service.

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans:it use software interrupt int 0x80 to invoke system call 

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:	call system for exit the program
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	13 is the lenght of the string.
