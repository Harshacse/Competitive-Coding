import random

def main():
	s = "1001\n"
	t = 10
	for i in range(0,1001):
		s += str(i)
		s += "\n"
	f = open("test.txt",'wb')
	f.write(s)

def tmain():
	s = "100\n"
	t = 10
	for i in range(100):
		s += str(random.randrange(1,10000))
		s += "\n"
	f = open("test.txt",'wb')
	f.write(s)
main()


