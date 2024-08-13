
void bs(int arr[],int ele)
{
 int mid,low=0,high=9;
 while(high>=low)
 {
   mid=(low+high)/2;
   if(arr[mid]==ele)
   {
    printf("%d element is find ",ele);
    break;
   }
   else if(arr[mid]>ele)
     high=mid-1;
   else
     low=mid+1;
 }
 if(high<low)
  printf("%d element is not found",ele);
}

void main()
{
  int arr[10]={10,20,30,40,50,60,70,80,90,100},s;
  clrscr();
  printf("\nEnter Search Element");
  scanf("%d",&s);
  bs(arr,s);
  getch();
}