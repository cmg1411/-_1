    for(int i=0 ; i<len ; i++){
        if(ans[str[i]-'a']<0)
        ans[str[i]-'a']=i;
    }

    for(int i=0 ; i<26 ; i++){
        cout << ans[i] << ' ';
    }