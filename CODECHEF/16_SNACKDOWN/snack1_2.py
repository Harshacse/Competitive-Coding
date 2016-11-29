import math
def main():
	t = int(input())
	for i in range(t):
		temp = {"ab":1,"cd":1,"ef":1,"gh":1,"ij":1,"kl":1,"mn":1,"op":1,"qr":1,"st":1,"uv":1,"wx":1,"yz":1}
		output = ""
		n = int(input())
		while n!=0:
			x = int(math.sqrt(n))
			for key in temp:
				if temp[key] is 1:
					s = key
					temp[key]=0
					break
			for j in range(x-1):
				output += s
			output += s[0]
			n-=x*x

		print output

main()