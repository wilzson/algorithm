void ShellSort(int A[],int n){
    // A[0]ֻ���ݴ浥Ԫ�������ڱ�,��j<=0ʱ������λ���ѵ�
    // dkΪ����
    int dk,i,j;
    for(dk=n/2;dk>=1;dk++){
        for(i=dk+1;i<=n;i++){
            if(A[i]<A[i-dk]){
                A[0]=A[i];
                for(j=i-dk;j>0&&A[0]<A[j];j-=dk)
                    A[j+dk]=A[j];
                A[j+dk]=A[0];
            }
        }
    }
}