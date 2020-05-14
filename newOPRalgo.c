 #include<stdio.h>
int optimalAlgoImpl(int[],int,int);
int full(int[],int);
int main()
{
int i,j,no_of_pages,page_sequence[50],no_frames,page_faults_opt;
             printf("\n ENTER THE NUMBER OF FRAMES :");
            scanf("%d",&no_frames);
            printf("\n ENTER THE NUMBER OF PAGES:\n");
            scanf("%d",&no_of_pages);
            printf("\n ENTER THE PAGE NUMBER :\n");
            for(i=0;i<no_of_pages;i++)
            scanf("%d",&page_sequence[i]);
           
           
          
           page_faults_opt=optimalAlgoImpl(page_sequence,no_of_pages,no_frames);
           printf("total page faults with OPR algorithm:  %d",page_faults_opt);
            return 0;
                        
            
            
}
     
     
         
//OPR algoritham implimentation
 
 optimalAlgoImpl(int page_sequence[],int no_of_pages,int alloc_frames)
   {
    int page_faults=0,i,frame[10],j=0,m=0,flag=0,hit=0,dup[10],k,frameFrequencyCount=0,min=0,min_index=0,frame_index=0,pages_replaced=0;
  //initializing frames with -1
    for(i=0;i<alloc_frames;i++)
    {
        frame[i]=-1;
    }
   
    //frame_indexing frames with out duplicates
    for(j=0;j<no_of_pages;j++)
      {
        //---------------------------
        for(i=0;i<alloc_frames;i++)
        {
             if(full(frame,alloc_frames)==1)//executes if frameame is not available
              {
                break;
              }
             else//checking for the page hit
              {
                  flag=0;
                  for(k=0;k<alloc_frames;k++)
                  {
                      if(page_sequence[j]==frame[k])
                      {
                          printf(" Element [%d]. ##### Page Hit found. ##### \n",frame[i]);
                           flag=1;
                          // printf("%d:\t",page_sequence[j]);
                           hit++;
                           break;
                      }
                  }
                  
                  if(flag==0)//placing page into frameame
                      {
                         page_faults++;
                          frame[frame_index]=page_sequence[j];
                          frame_index++;
                          //printf("%d:\t",page_sequence[j]);
                           printf(" Element [%d]. ##### Page Fault found. ##### Inserted into available frames.\n",page_sequence[j]);
                          j++;
                      }
		       /*for printing elemrnts in the frameame
                        for(i=0; i<alloc_frames; i++)
                         printf(" %d  ",frame[i]);
                        printf("\n"); */
           
            }
        
         }
    }
  
        //-------------------------------
       //checking page already present in the frames
     for(j=alloc_frames;j<no_of_pages;j++)
     {
         
         flag=0;
       for(i=0;i<alloc_frames;i++)
        {
         if(page_sequence[j]==frame[i])
         { 
             printf(" Element [%d]. ##### Page Hit found. ##### \n",frame[i]);
             flag=1;
             hit++;
             break;
             //need to start frameom start
         }
        }
       if(flag==0)
         {
             //comparing and counting the frameequency of pages which are present in the frameame
             
             page_faults++;
             pages_replaced++;
             printf(" Element [%d]. ##### Page Fault found. ##### Inserted into available frames.\n",page_sequence[j]);
             for(k=0;k<alloc_frames;k++)
             {
                 for(i=j+1;i<no_of_pages;i++)
                 {
                   if(frame[k]==page_sequence[i])
                    {
                       //framefreequency counting
                       frameFrequencyCount++;
                       
                    }
                   
                 }
                 dup[k]=frameFrequencyCount;
             }
             //frame_indexnding min frameequency
             for(i=0;i<alloc_frames;i++)
             {
                 if(frame[i]<min)
                 {
                     min=dup[i];
                     min_index=i;
                 }
                 
             }
             
             frame[min_index]=page_sequence[j];
         }
     } 
    // printf("\ntotal page faults with OPR algorithm: %d\n",page_faults);
       printf("total page hits with OPR algorithm: %d\n",hit);
       printf("\ntotal number of pages replaced with OPR algoritham: %d\n",pages_replaced);
    
    return(page_faults);
     }
  
 //checking whether frameame is full or not 
 int full(int a[],int n)
{
    int k;
    for(k=0; k<n; k++)
    {
        if(a[k]==-1)
            return 0;
    }
    return 1;
}

 