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
	pushl %edx		# auxiliary

	movl 8(%ebp), %eax
	movl 12(%ebp), %ebx
	movl $max_categories, %ecx
	movl $0, %edx

	# get to the categories field in the struct
	addl $4, %ecx
	addl %ecx, %eax

	start_f1:
		cmpl %edx, $max_categories
		jge end_f1

		cmpl $1, (%ebx)


	jmp start_f1
	end_f1:

	popl %edx
	popl %ecx
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
