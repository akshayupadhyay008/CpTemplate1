ill *st;
ill findGcd(ill ss, ill se, ill qs, ill qe, ill si)
{
    if (ss>qe || se < qs)
        return 0;
    if (qs<=ss && qe>=se)
        return st[si];
    ill mid = ss+(se-ss)/2;
    return __gcd(findGcd(ss, mid, qs, qe, si*2+1),
               findGcd(mid+1, se, qs, qe, si*2+2));
}
  

ill findRangeGcd(ill ss, ill se, ill arr[],ill n)
{
    if (ss<0 || se > n-1 || ss>se)
    {
        // cout << "Invalid Arguments" << "\n";
        return -1;
    }
    return findGcd(0, n-1, ss, se, 0);
}
  
ill constructST(ill arr[], ill ss, ill se, ill si)
{
    if (ss==se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    ill mid = ss+(se-ss)/2;
    st[si] = __gcd(constructST(arr, ss, mid, si*2+1),
                 constructST(arr, mid+1, se, si*2+2));
    return st[si];
}
  
ill *constructSegmentTree(ill arr[], ill n)
{
   ill height = (ill)(ceil(log2(n)));
   ill size = 2*(ill)pow(2, height)-1;
   st = new ill[size];
   constructST(arr, 0, n-1, 0);
   return st;
}
