//#include <stdio.h>
//#include <stdlib.h>
//
//struct grade
//{
//    int score;
//    struct grade *next;
//};
//
//typedef struct grade NODE;
//
//struct grade *create(); //创建链表
//void insert(NODE *head, NODE *pnew,int i); //插入链表
//void pdelete(NODE *head,int i); //删除链表
//void display(NODE *head); //输出链表
//void pfree(NODE *head); //销毁链表
//
//
//
//int main(int argc,char *argv[])
//{
//    struct grade *head,*pnew;
//    head = create();
//    if(NULL == head)
//    {
//        return 0 ;
//    }
//    printf("输出创建的链表：");
//    display(head);
//    pnew = (NODE *)malloc(sizeof(NODE));
//    if(pnew == NULL)
//    {
//        printf("创建失败！");
//        return 0;
//    }
//    pnew->score = 88 ;
//    insert(head,pnew,3); //将新节点插入节点3的后面
//    printf("插入后的链表：");
//    display(head);
//    pdelete(head,3); //删除节点3
//    printf("删除后的链表：");
//    display(head);
//    pfree(head);
//    return 0;
//}
//
//
////创建一个链表
//struct grade *create()
//{
//    NODE *head,*tail,*pnew;
//    int score;
//    head = (NODE *) malloc(sizeof(NODE));
//    if(NULL == head)
//    {
//        printf("创建失败！");
//        return NULL;
//    }
//    head->next = NULL; //头结点指针域置NULL
//    tail = head; //开始时尾指针指向头结点
//    printf("输入学生成绩：");
//    while(1)
//    {
//        scanf("%d",&score);
//        if(score < 0 ) //成绩为负则退出循环
//            break;
//        pnew = (NODE *)malloc(sizeof(NODE));
//        if(pnew == NULL)
//        {
//            printf("创建失败！");
//            return NULL;
//        }
//        pnew->score = score; //新节点数据域存放输入的成绩
//        pnew->next = NULL;   //新节点指针域置NULL
//        tail->next = pnew;   //新节点插入到表尾
//        tail = pnew;         //尾指针指向当前的尾节点
//    }
//    return head;  //返回创建链表的头指针
//}
//
//
//
////在第i个节点处插入一个节点
//void insert(NODE *head,NODE *pnew,int i)
//{
//    NODE *p; //当前指针
//    //int j;
//    p = head ;
//    for (int j = 0 ; j < i && p != NULL; j++) //p指向要插入的第i个节点
//        p = p->next;
//    if(p == NULL)
//    {
//        printf("插入的节点不存在！");
//        return ;
//    }
//    pnew->next = p->next;  //插入节点的指针域指向第i个节点的后继节点
//    p->next = pnew;
//}
//
//void pdelete(NODE *head,int i )
//{
//    NODE *p,*q;
//    int  j ;
//    if(i == 0 ) // 删除的是头指针，返回
//        return ;
//    p = head;
//    for(j = 1; j < i && p->next != NULL; j++)
//        p = p->next ; // 将p指向要删除的第i个节点的前驱节点
//    if(p->next == NULL)
//    {
//        printf("不存在！");
//        return ;
//    }
//    q = p->next; //q指向待删除的节点
//    p->next = q->next; //删除节点i，也可写成p->next = p->next->next
//    free(q); //释放节点i的内存单元
//}
//
//void display(NODE *head)
//{
//    NODE *p;
//    for(p = head->next;p!= NULL ;p = p->next)
//        printf("%d ",p->score);
//    printf("\n");
//}
//void pfree(NODE *head)
//{
//    NODE *p,*q;
//    p = head ;
//    while(p->next != NULL)
//    {
//        q = p->next;
//        p->next = q->next;
//        free(q);
//    }
//    free(p);
//}




//#include <stdio.h>
//#include <stdlib.h>
//
//
////#define NULL (void)0
//
//struct student
//{
//    long num ;
//    float score;
//    struct student *next;
//};
//
//int main()
//{
//    struct student a,b,c,*head,*p;
//    a.num = 99101;a.score = 89.5;
//    b.num = 99103;b.score = 90;
//    c.num = 99107;c.score = 85;
//    head = &a;
//    a.next = &b;
//    b.next = &c;
//    c.next = NULL;
//    p = head;
//    do
//    {
//        printf("%ld %5.1f\n",p->num,p->score);
//        p = p->next;
//    }while(p!=NULL);
//    return 0 ;
//}




//#include <stdio.h>
//#include <stdlib.h>
//
//
//struct student
//{
//    int num;
//    float score;
//    struct student *next;
//};
//
///*创建一个只有头结点的空链表*/
//struct student* Create()
//{
//    struct student *head;
//    head = (struct student*)malloc(sizeof(struct student));
//    if(head == NULL)
//    {
//        printf("申请头结点失败！\n");
//        return NULL;
//    }
//    head->next = NULL;
//    return head;
//}
//
///*将s指向的结点插入链表，使链表保持升序，并返回头结点*/
//struct student *Insert(struct student *head,struct student *s)
//{
//    struct student *p = head;
//    while(p->next != NULL && s->score > p->next->score)
//    p = p->next;
//    if(p->next == NULL) //s->score 最大的情况
//    {
//         s->next = NULL;
//         p->next = s; //连接结点
//    }
//    else
//    {
//        s->next = p->next;
//        p->next = s; //连接结点q
//    }
//    return head;
//}
///*查找符合条件的结点，并返回指向该结点的指针*/
//struct student *search(struct student *head)
//{
//    struct student *p = head->next ;
//    int num ;
//    printf("请输入要查找学生的学号：\n");
//    scanf("%d",&num);
//    while(p != NULL && p->num != num)
//        p = p->next;
//    if(p == NULL)
//    {
//        printf("找不符合条件的结点！！");
//        return NULL;
//    }
//    if(p->num == num)
//    {
//        printf("找到符合条件的结点\n该结点为%d\t%f",p->num,p->score);
//        return p;  //返回查找到的指针
//    }
//}
///*输出链表各结点的值，也称对链表的遍历*/
//void print(struct student *head)
//{
//    struct student *p;
//    printf("    链表如下：\n");
//    p = head->next;
//    while(p != NULL)
//    {
//        printf("%d\t%.1f\n",p->num ,p->score);
//        p = p->next;
//    }
//}
///*释放链表*/
//void free_list(struct student *head)
//{
//    struct student *p = head;
//    print("释放链表：\n");
//    while(p != NULL)
//    {
//        head = head->next ;
//        free(p);
//        p = head;
//    }
//    printf("释放链表成功！\n");
//}
//
///*删除链表中值为num的结点，并返回链表的首指针*/
//struct student *delete_note(struct student *head,int num_x)
//{
//    struct student *p1 = head->next,*p2 = head;
//    while(p1 != NULL && p1->num != num_x)
//    {
//        p2 = p1 ;
//        p1 = p1->next;
//    }
//    if(p1 == NULL)
//    {
//        printf("找不到符合删除要求的结点！！\n");
//    }
//    if(p1->num == num_x)
//    {
//        p2->next = p1->next;
//        free(p1);
//        printf("结点删除成功！\n");
//    }
//    return head;
//}
//
///*完整的有头结点链表操作程序*/
//int main()
//{
//    struct student *p,*head;
//    char c ;
//    int num ;
//    float score;
//    printf("有头结点链表操作程序：\n");
//    head = Create();
//    while(1)
//    {
//        printf("I:插入结点(自动升序)  P:输出链表  S:查找结点  D:删除结点  E:释放链表并退出程序!  ");
//        c=getch();
//		switch(c)
//		{
//			case'I':
//				printf("请分别输入要插入学生的学号和分数:\n");
//				scanf("%d%f",&num,&score);
//				p=(struct student*)malloc( sizeof(struct student) );
//				if(p==NULL)
//					{
//						printf("申请该结点失败!!!\n");
//						exit (0) ;
//					}
//				p->num=num;  p->score=score;   //给p赋值
//				Insert(head,p);
//				printf("插入成功!\n");
//				break;
//			case'P':
//				print(head);
//				break;
//			case'S':
//				search(head);
//				break;
//			case'D':
//				printf("请输入要删除的学生的学号:\n");
//				scanf("%d",&num);
//				delete_note(head,num);
//				break;
//			case'E':
//				free_list(head);
//				exit (0);
//		}
//    }
//    return 0 ;
//}

//
//#include<stdio.h>
//#include<malloc.h>
//#define NULL 0
//#define LEN sizeof(struct student)
//#include<conio.h>
//#include<string.h>
//#include<stdlib.h>
//struct student
//{
//  long num;
//  float tel;
//  char add[10];
//  long zip;
//  struct student *next;
//};
//int n;                               /* n 为全局变量，用于统计结点的个数*/
///*―――――――---――――-―――creat函数――――――----――――――――*/
//struct student *creat()                            /* 创建creat函数用于建立链表*/
//{
//  struct student *head;
//  struct student *p1,*p2;
//  n=0;
//  p2=(struct student *)malloc(LEN);               /* 开辟一个大小为LEN的内存单元*/
//  p1=p2;
//  printf("请输入学号:");scanf("%ld",&p1->num);             /* 输入学号*/
//  if(p1->num!=0)
//    { printf("请输入电话:");scanf("%f",&p1->tel);        /* 输入电话号码*/
//      printf("请输入地址:");scanf("%s",p1->add);          /* 输入地址*/
//      printf("请输入邮编:");scanf("%ld",&p1->zip);         /* 输入邮编*/
//      printf("ok! 请输入下一个结点的信息\n");          /* 提示已经输好了一位同学的信息*/
//    }
//  head=NULL;
//  while(p1->num!=0)                      /* 如果输入的学号不是0，刚继续输入其余的同学的信息*/
//    { n=n+1;
//      if(n==1) head=p1;
//      else p2->next=p1;
//      p2=p1;
//      p1=(struct student *)malloc(LEN);
//      printf("请输入学号:");scanf("%ld",&p1->num);
//      if(p1->num!=0)
//        { printf("请输入电话:");scanf("%f",&p1->tel);
//          printf("请输入地址:");scanf("%s",p1->add);
//          printf("请输入邮编:");scanf("%ld",&p1->zip);
//          printf("ok! 请输入下一个结点的信息\n");
//        }
//     }
//  p2->next=NULL;
//  return  head;                                    /* 结束creat函数*/
//}
///*―――――――---――――-―――print函数――――――----――――――――*/
//void print(struct student *head)                   /* 开始打印函数*/
//{ struct student *p;
//  printf("\n Now,These %d records are:\n",n);
//  p=head;
//  if(head!=NULL)                                   /* 如果链表不是空，则打印每个结点信息*/
//    {    printf("-------------|------------ |-------------|--------\n");
//          printf("学号        |电话        |地址        |邮编   \n");
//      do
//       { printf("-------------|------------ |-------------|--------\n");
//         printf("0%-12ld|%-13.0f|%-13s|%-13ld\n",p->num,p->tel,p->add,p->zip);
//         p=p->next;
//       }while(p!=NULL);
//         printf("-------------|------------ |-------------|--------\n");
//     }
//  else printf("链表是空的!\n");                /* 如果链表是空表，刚提示这个链表是空表*/
//}                                                  /* 结束print函数*/
///*―――――――---――――---―――del函数――――――-----――――――――*/
//struct student *del(struct student *head,long num)           /* 开始创建del函数，用于删除结束*/
//{ struct student *p1,*p2;
//  if(head==NULL) {printf("\n链表是空的!\n"); return head; }   /* 用于检查链表是否为空，如果为空，刚提示这个链表为空表*/
//  p1=head;
//  while(num!=p1->num && p1->next!=NULL)
//    {p2=p1;p1=p1->next;}
//  if(num==p1->num)                                        /* 找到对应的结点*/
//    { if(p1==head) head=p1->next;
//      else p2->next=p1->next;
//      printf("删除:0%ld\n",num);
//      n=n-1;
//     }
//  else printf("0%ld 没有找到!\n",num);                       /* 没有打到对应的结点，则提示没有找到*/
//  return head;
//}
///*―――――――---――――-―――insert函数――――――----――――――――*/
//struct student *insert(struct student *head,struct student *lnew)   /* 创建insert函数，用于插入结点，返回值为一个指针*/
//{ struct student *p0,*p1,*p2;
//  p1=head;
//  p0=lnew;
//  if(head==NULL)  {head=p0;p0->next=NULL;}   /* 结果链表为空表，刚把插入的结点指针给头指针，结点的next为空*/
//  else
//      { while((p0->num>p1->num) && (p1->next!=NULL))       /* 寻找该插入的位置*/
//          {p2=p1;
//           p1=p1->next;
//           }
//        if(p0->num<=p1->num)                              /* 找到了该插入的位置*/
//          {if(head==p1) head=p0;                                     /* 放在最前面*/
//           else p2->next=p0;                                         /* 结点插到p1,p2之间*/
//           p0->next=p1;
//           }
//        else {p1->next=p0;p0->next=NULL;}                              /* 结点插到最后*/
//       }
//  n=n+1;
//  return head;                                                        /* 结点数加*/
//}                                                                    /* 结束insert函数的建立*/
///*―――――――---――――-―――menubar函数――――――----――――――――*/
//int menubar()                                                        /*创建菜单函数*/
//{ int flag=1;                                                       /*用来做记号*/
//  int c;                                                          /*用来存储使用者选择的菜单代号*/
//  printf("\n\n************** 链表综合处理 ****************\n");
//  printf("0:创建链表                                  ----\n");
//  printf("1:输出链表\n");
//  printf("2:插入结点                                  菜单\n");
//  printf("3:删除结点\n");
//  printf("4:退出                                      ----\n");
//  printf("*************************************************");
//  printf("\n请根据你想执行的命令，输入对应的0~4的数:");
//  scanf("%d",&c);                                                   /*接收使用都所输入的代号*/
//  while(flag)         /*flag用来标记，如果为链表为空，或者使用者第一次输入的不是0或者不是4，则需要重新输入*/
//    {if(n==0&&c!=0&&c!=4)
//      {printf("在建立链表之前请先输入建立链表\n");
//       printf("\n请输入0~4的数:");
//       scanf("%d",&c);
//       flag=1;
//       }
//     else flag=0 ;
//    }
// while( c<0 || c>4 )                              /*表示链表已经创建，但输入的不能大于4，或者小于0*/
//  { printf("\n请输入~4的数:");
//    scanf("%d",&c);
//  }
//return c;                                             /*返回c的值*/
// }
///*―――――――---――――-―――main函数――――――----――――――――*/
//void main()                                              /*开始主函数*/
//{
//    struct student *head,*lnew;
//    long del_num;
//    for(;;)                                                      /*开始for循环*/
//    {
//        switch (menubar())
//        { case 0:printf("请输入创建的链表的结点的信息:\n");
//                 head=creat();
//                 break;
//          case 1:print(head);
//                 break;
//          case 2: printf("\n请输入要插入的结点的信息:\n");
//                 lnew=(struct student *)malloc(LEN);
//                 printf("请输入学号：");scanf("%ld",&lnew->num);
//                 if(lnew->num!=0)
//                   { printf("请输入电话:");scanf("%f",&lnew->tel);
//                     printf("请输入地址:");scanf("%s",lnew->add);
//                     printf("请输入邮编:");scanf("%ld",&lnew->zip);
//                   }
//                 while(lnew->num!=0)
//                   { head=insert(head,lnew);
//                     print(head);
//                     printf("请输入下一个要插入的结点的信息:\n");
//                     lnew=(struct student *)malloc(LEN);
//                     printf("请输入学号:");scanf("%ld",&lnew->num);
//                     if(lnew->num!=0)
//                        { printf("请输入电话");scanf("%f",&lnew->tel);
//                          printf("请输入地址:");scanf("%s",lnew->add);
//                          printf("请输入邮编:");scanf("%ld",&lnew->zip);
//                          printf("ok! 请输入下一个要插入的结点的信息\n");
//					    }
//                    }
//                 break;
//         case 3:printf("\n请输入你想删除的结点的学号:");
//                scanf("%ld",&del_num);
//                while(del_num!=0)
//                { head=del(head,del_num);
//                  print(head);
//                  printf("\n请输入你想删除的结点的学号:");
//                 scanf("%ld",&del_num);
//                }
//                break;
//        case 4: system("CLS");
//                printf("谢谢您的使用\n\n\n\n");
//                getch();
//                exit(0);                                            /*退出for循环*/
//        }
//   }
//}                                                                   /*结束主函数*/



