def main():
	t = int(input())
	s = 0
	p = 1
	for i in range(6):
		s += p
		p = p*t

	print s

main()