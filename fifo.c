 #include<stdio.h>
int FIFOalgo(int[],int,int);
int main()
{
int i,j,no_of_pages,page_number[50],frame[10],no_of_frames,k,avail,count=0,page_faults;
            printf("\n ENTER THE NUMBER OF PAGES:\n");
            scanf("%d",&no_of_pages);
            printf("\n ENTER THE PAGE NUMBER :\n");
            for(i=1;i<=no_of_pages;i++)
            scanf("%d",&page_number[i]);
            printf("\n ENTER THE NUMBER OF FRAMES :");
            scanf("%d",&no_of_frames);
           page_faults=FIFOalgo(page_number,no_of_pages,no_of_frames);
           printf("total number of page_faults:%d",page_faults);
            return 0;
            
}
     
 FIFOalgo(int page_number[],int no_of_pages,int no_of_frames)
 {          
  int i,j,k,avail,count=0,frame[10];
                    
     for(i=0;i<no_of_frames;i++)
      frame[i]= -1;
      j=0;
      printf("\tref string\t page frames\n");
      for(i=1;i<=no_of_pages;i++)
       {
          printf("%d\t\t",page_number[i]);
          avail=0;
            for(k=0;k<no_of_frames;k++)
              if(frame[k]==page_number[i])
                  avail=1;
                if (avail==0)
                  {
                     frame[j]=page_number[i];
                     j=(j+1)%no_of_frames;
                     count++;
                     for(k=0;k<no_of_frames;k++)
                     printf("%d\t",frame[k]);
                    }
                                    printf("\n");
         }
          //printf("Page Fault Is %d",count);
          return count;
            }
          
123421
123
423

page fault
replacements
hits


