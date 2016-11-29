import random

def main():
	t = 30;
	s = str(t)+"\n"
	while t>0:
		t = t-1
		n = random.randrange(1,100000)
		s += str(n) +"\n"
		for i in range(n):
			s += str(random.randrange(1,10000))
			s += " "
		s+= "\n"
	f = open("test.txt",'wb')
	f.write(s)
	f.close()

main()
