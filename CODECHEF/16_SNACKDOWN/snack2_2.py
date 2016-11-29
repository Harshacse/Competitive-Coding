def main():
	t = int(input())
	for i in range(t):
		x = raw_input()
		N = int(x.split(" ")[0])
		K = int(x.split(" ")[1])
		x = raw_input()
		lis = []
		a = x.split(" ")
		for j in range(N):
			lis.append(int(a[j]))
		temp = sorted(lis,key=abs)
		prod = 1
		temp.reverse()
		for j in range(K):
			prod *= temp[j]
		if(prod>=0):
			print prod%(10**9+7)
			continue
		else:
			j= K-1
			while j>=0:
				if temp[j]<0:
					leftmin = temp[j]
					break
				j-=1
			k = K-1
			while k>=0:
				if temp[k]>0:
					leftmax = temp[k]
					break
				k-=1
			l = K
			while l<N:
				if temp[l]<0:
					rightmin = temp[l]
					break
				l+=1
			m = K
			while m<N:
				if temp[m]>0:
					rightmax = temp[m]
					break
				m+=1
			maxi = -999999999
			if j!=-1 and m!=N:
				maxi = (prod/leftmin)*rightmax
			if k!=-1 and l!=N:
				if maxi < (prod/leftmax)*rightmin:
					maxi = (prod/leftmax)*rightmin
			if ((j is -1)or(m is N))and((k is -1)or(l is N)):
				prod = 1
				for x in range(N-K,N):
					prod *= temp[x]
				print prod%(10**9+7)
				continue
			print maxi%(10**9+7)


main()