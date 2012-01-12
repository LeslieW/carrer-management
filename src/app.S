# ##############################################################################
#
#	app.S
#
#	Assembly implementation of the following functions:
#
#		* appLoadCategories()
#		* appGetCurrentCategory()
#		* appCountCategories()
#		* appNumEmployeesInCategory()
#
#	Created at:
#
#		2012-01-11
#
#	Author(s):
#
#		B5-8 LAPRIII group
#
# ##############################################################################

	.text

	.global max_categories
	.global max_employee_name

	.global appLoadCategories
	.global appGetCurrentCategory
	.global appCountCategories
	.global appNumEmployeesInCategory

appLoadCategories:
	#
	#	first arg: employee struct
	#	second arg: category array
	#

	pushl %ebp
	movl %esp, %ebp
	pushl %eax		# ptr to first argument
	pushl %ebx		# ptr to second argument
	pushl %ecx		# number of bytes to move
	pushl %edx		# counter

	movl 8(%ebp), %eax
	movl 12(%ebp), %ebx
	movl max_employee_name, %ecx
	movl $0, %edx

	# get to the categories field in the struct
	addl $4, %ecx
	addl %ecx, %eax

	movl (%eax), %ecx

	# we iterate through the 32 bits, checking
	# each bit if it's active, then writing it
	# to the category array
	start_f1:
		cmpl %edx, max_categories
		jle end_f1

		movl %ecx, %eax
		andl $0x00000001, %eax
		shrl $1, %ecx

		cmpl $1, %eax
		jne cont_f1

		movl $1, (%ebx)

		cont_f1:
		incl %edx
		addl $4, %ebx		

	jmp start_f1
	end_f1:

	popl %edx
	popl %ecx
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret

appGetCurrentCategory:
	pushl %ebp
	movl %esp, %ebp
	pushl %eax		# ptr to first argument
	pushl %ebx		# ptr to second argument
	pushl %ecx		# number of bytes to move
	pushl %edx		# counter
	
	movl 8(%ebp), %eax
	movl 12(%ebp), %ebx
	movl max_employee_name, %ecx
	movl $0, %edx

	# get to the categories field in the struct
	addl $4, %ecx
	addl %ecx, %eax

	movl (%eax), %ecx

	# we shift bit by bit to the right,
	# until the MSB is active. This will be
	# the current category, because the hightest
	# one is always the current one
	start_f2:
		cmpl %edx, max_categories
		jle end_f2

		movl %ecx, %eax
		andl $0x80000000, %eax
		shll $1, %ecx

		cmpl $0, %eax
		je cont_f2

		movl max_categories, %eax
		subl %edx, %eax
		decl %eax
		movl %eax, (%ebx)
		jmp end_f2

		cont_f2:
		incl %edx

	jmp start_f2
	end_f2:

	popl %edx
	popl %ecx
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret

appCountCategories:
	pushl %ebp
	movl %esp, %ebp
	pushl %eax		# ptr to first argument
	pushl %ebx		# ptr to second argument
	pushl %ecx		# number of bytes to move
	pushl %edx		# counter

	movl 8(%ebp), %eax
	movl 12(%ebp), %ebx
	movl max_employee_name, %ecx
	movl $0, %edx
	movl $0, (%ebx)

	# get to the categories field in the struct
	addl $4, %ecx
	addl %ecx, %eax

	movl (%eax), %ecx

	# we check bit by bit, which are active and
	# increase the count	
	start_f3:
		cmpl %edx, max_categories
		jle end_f3

		movl %ecx, %eax
		andl $0x00000001, %eax
		shrl $1, %ecx

		cmpl $0, %eax
		je cont_f3

		addl $1, (%ebx)		

		cont_f3:
		incl %edx

	jmp start_f3
	end_f3:

	popl %edx
	popl %ecx
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
