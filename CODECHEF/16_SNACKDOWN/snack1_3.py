def gcd(c,d):
	if(c>d):

		if(c%d==0):
			return d
		else:
			return gcd(d,c%d)
	else:
		if(d%c==0):
			return c
		else:
			return gcd(c,d%c)

def main():
	t = int(input())
	for i in range(t):
		x = raw_input()
		x = x.split(" ")
		a = int(x[0])
		b = int(x[1])
		c = int(x[2])
		d = int(x[3])
		temp = gcd(c,d)
		if(a>b):
			result = min((a-b)%temp,temp-(a-b)%temp)
		else:
			result = min((b-a)%temp,temp-(b-a)%temp)
		print result

main()