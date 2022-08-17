int norm(int pks[],int elem)
{
  int sum=0;
  for(int i=0;i<sizeof(pks)/sizeof(int);i++)
  {
    sum=sum+sq(pks[i]-elem);
    
    }
    return sqrt(sum);
  }
