int peakdet(int sig[],int th=0.5,int mdist=0)
{

  int L=sizeof(sig)/sizeof(int);
  
  int pks[L];
  int dep[L];
  
  int pks_i=0;

  int dep_i=0;
  
   int pid[L]={};
  int did[L]={};
   int cross=0;
   int idx=0;   
   int idn=0;
   bool lookpks;
   int mx=-2147483647;
   int mn=2147483647;
   int mxpos;
   int mnpos;

  if(sizeof(th)>1)
  {
    Serial.print("error");
    
    }
    if(th<1)
    {
      Serial.print("error");
      }
       int i=0;
       while(i<L)
       {
      if(sig[i]<th)
      {
        i++;
      
       
        }
        else
        {idx=i;
        break;
        
        }
       }
       
        while(i<L )
        {
          
        if(sig[i]>th)
      {
        i++;
      
       
        }
        else
        {idn=i;
        break;
        }
        }
        if(idx<idn)
        {
          lookpks=true;
          
        }
        else
        {
          lookpks=false;
          }
          for(int ii=0;ii<L;ii++)
          {

            
            int thiss=sig[ii];
            if(thiss>mx)
            {
              mx=thiss;
              mxpos=ii;
              }
              if(thiss<mn)
              {
                mn=thiss;
                mnpos=ii;
                }
                if(lookpks)
                {
                  if(thiss<cross)
                  {
                    if(mx>=th)
                    {
                      pks[pks_i]=mx;
                      pid[pks_i]=mxpos;
                      pks_i++;
                      }
                      mn=thiss;
                      mnpos=ii;
                      lookpks=false;
                    }
                    else
                    {
                      if(thiss>(-cross))
                      {
                        if(mn<=(-th))
                        {
                          dep[dep_i]=mn;
                          did[dep_i]=mnpos;
                          dep_i++;
                          }
                        }
                      }
                



                
                  }
            }

            if(lookpks)
                {
                  
                    if(mx>=th)
                    {
                      pks[pks_i]=mx;
                      pid[pks_i]=mxpos;
                      pks_i++;
                      }
                      
                    }
                    else
                    {
                      
                        if(mn<=(-th))
                        {
                          dep[dep_i]=mn;
                          did[dep_i]=mnpos;
                          dep_i++;
                          }
                        }
                        //remove smaller peaks and stuff
                        if(mdist>0)
                        {
                        for(int i=0;i<pks_i;i++)

                        {
                         int d=norm(pks,pks[i]);
                          if((pks[i]<pks[i+1]) && (d<mdist))
                          {
                            //pks[i]=0;
                            for(int j=i; j<pks_i;j++)
                            {
                              pks[j]=pks[j+1];
                              pks_i--;
                              }
                            }
                          }

                        } 
                        
                        for(int i=0;i<dep_i;i++)

                        {
                         int d=norm(dep,dep[i]);
                          if((dep[i]<dep[i+1]) && (d<mdist))
                          {
                            //dep[i]=0;
                            for(int j=i; j<dep_i;j++)
                            {
                              dep[j]=dep[j+1];
                              pks_i--;
                              }
                            }
                          }

                       int retVar[4]={pks,pid,dep,did};
                       
                      
                        
                      
                
                return retVar;
}
                      

            

