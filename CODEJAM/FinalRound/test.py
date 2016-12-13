import random

def main():
	t = 3;
	s = "3\n"
	while t>0:
		n = random.randrange(100000,750000)
		s += str(n) + "\n"
		for i in range(n):
			s += str(random.randrange(1,750000))
			s += " "
		s += "\n"
		t = t-1

	f = open("test.txt",'wb')
	f.write(s)
	f.close()

main()