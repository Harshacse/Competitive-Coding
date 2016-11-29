
def main():
	t = int(input())
	for i in range(t):
		k = int(input())
		output = ""
		for j in range(k):
			output += str(2*j+1)
			output += " "
		for j in range(k-1):
			output += str(2*j+2)
			output += " "
		output += str(2*k)
		print 2*k
		print output
main