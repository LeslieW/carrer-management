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
	
appNumEmployeesInCategory:
	pushl %ebp
	movl %esp, %ebp
	pushl %eax		# ptr to first argument
	pushl %ebx		# ptr to second argument
	pushl %ecx		# ptr to third argument
	pushl %edx		# ptr to fourth argument
	pushl %edi		# counter
	pushl %esi		# number of bytes to move/current employee category
	
	movl 8(%ebp), %eax
	movl 12(%ebp), %ebx
	movl 16(%ebp), %ecx
	movl 20(%ebp), %edx
	movl $0, %edi
	movl max_employee_name, %esi
	
	# get to the categories field in the struct
	addl $4, %esi
	addl %esi, %eax

	movl (%eax), %edx
	
	start_f4_1:
		cmpl %edi, %ebx
		jle end_f4_1
		
		# we must reutilize some additional
		# registers
		movl $0, %eax
		movl $0, %ebx
		
		start_f4_2:
			cmpl max_categories, %eax
			jge end_f4_2
			
			movl %edx, %ebx
			andl $0x00000001, %ebx
			shrl $1, %edx
			
			# check if we're on the category we want
			cmpl $0, %ebx
			je cont_f4_2
			cmpl %ecx, %ebx
			jne cont_f4_2
			
			# get back the category counter and increment
			movl 20(%ebp), %ebx
			addl %eax, (%ebx)
			
			# if this employee is in this category,
			# we go on to the next one
			jmp end_f4_f2
			
			cont_f4_2:
			incl %eax
		
		jmp start_f4_2
		end_f4_f2:
		
		# get the first argument again
		movl 8(%ebp), %eax
		
		# get the second argument again
		movl 12(%ebp), %ebx
		
		# increment the employee array counter
		incl %edi
		
		# point %eax to the next employee
		movl $4, %esi
		addl max_exmployee_name, %esi
		mull %edi, %esi
		addl %esi, %eax
		movl (%eax), %edx
	
	jmp start_f4_1
	end_f4_1:
	
	popl %esi
	popl %edi
	popl %edx
	popl %ecx
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret