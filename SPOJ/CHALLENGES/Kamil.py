while(True):
	try:
		s = raw_input()
		print 2**s.count('T')*2**s.count('D')*2**s.count('L')*2**s.count('F')
	except EOFError:
		break