/*
 * Complete the function below.
 */

int replacements(string s) {
    cout<<s.length();
    string temp;
    int n=s.length(),i,j,k,pos,count,ans=20001;
    for(pos=0; pos<=(n/2-1-7) ; pos++ )
    {
        count=0;
        for(j=0 ; j<pos ;j++)
            {
            if(s[j]!=s[n-1-j])
                count++;
        }
        temp="linkedin";
        for(j=pos; j<=pos+7 ; j++)
            {
            if(s[j]!=temp[j-pos])
                count++;
        }
        k=0;
        for(j=n-pos-1; j >=n-pos-8; j--)
            {
            if(s[j]!=temp[k])
                count++;
            k++;
        }
        for(j=pos+8 ; j<=(n/2-1) ;j++)
            {
            if(s[j]!=s[n-1-j])
                count++;
        }
        ans=min(ans,count);
    }
    for(pos=(n+1)/2 ; pos<=n-8 ; pos++){
        count=0;
        for(j=n-1 ; j>=pos+8 ; j--)
        {
            if(s[j]!=s[n-1-j])
                count++;
        }
        temp="nideknil";
        k=0;
        for(j=pos+7 ; j>=pos ; j--){
            if(s[j]!=temp[k])
                count++;
            k++;
        }
        temp="linkedin";
        k=0;
        for(j=n-1-pos; j>=n-pos-8 ; j--){
            if(s[j]!=temp[k])
                count++;
            k++;
        }
        for(j=pos-1;j>=n/2 ; j--){
            if(s[j]!=s[n-1-j])
                count++;
        }
        ans=min(ans,count);
    }
    if(n%2==1){
        int mid=n/2;
        count=0;
        for(j=0;j<=mid-6;j++){
            if(s[j]!=s[n-1-j])
                count++;
        }
        temp="linkedinideknil";
        k=0;
        for(j=mid-7;j<=mid+7;j++){
            if(s[j]!=temp[k])
                count++;
            k++;
        }
        ans=min(ans,count);
        count=0;
        for(j=0;j<=mid-6;j++){
            if(s[j]!=s[n-1-j])
                count++;
        }
        temp="nideknilinkedin";
        k=0;
        for(j=mid-7;j<=mid+7;j++){
            if(s[j]!=temp[k])
                count++;
            k++;
        }
        ans=min(ans,count);
    }
    return ans;
}

