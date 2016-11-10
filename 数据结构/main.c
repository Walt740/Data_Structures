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
//struct grade *create(); //��������
//void insert(NODE *head, NODE *pnew,int i); //��������
//void pdelete(NODE *head,int i); //ɾ������
//void display(NODE *head); //�������
//void pfree(NODE *head); //��������
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
//    printf("�������������");
//    display(head);
//    pnew = (NODE *)malloc(sizeof(NODE));
//    if(pnew == NULL)
//    {
//        printf("����ʧ�ܣ�");
//        return 0;
//    }
//    pnew->score = 88 ;
//    insert(head,pnew,3); //���½ڵ����ڵ�3�ĺ���
//    printf("����������");
//    display(head);
//    pdelete(head,3); //ɾ���ڵ�3
//    printf("ɾ���������");
//    display(head);
//    pfree(head);
//    return 0;
//}
//
//
////����һ������
//struct grade *create()
//{
//    NODE *head,*tail,*pnew;
//    int score;
//    head = (NODE *) malloc(sizeof(NODE));
//    if(NULL == head)
//    {
//        printf("����ʧ�ܣ�");
//        return NULL;
//    }
//    head->next = NULL; //ͷ���ָ������NULL
//    tail = head; //��ʼʱβָ��ָ��ͷ���
//    printf("����ѧ���ɼ���");
//    while(1)
//    {
//        scanf("%d",&score);
//        if(score < 0 ) //�ɼ�Ϊ�����˳�ѭ��
//            break;
//        pnew = (NODE *)malloc(sizeof(NODE));
//        if(pnew == NULL)
//        {
//            printf("����ʧ�ܣ�");
//            return NULL;
//        }
//        pnew->score = score; //�½ڵ�������������ĳɼ�
//        pnew->next = NULL;   //�½ڵ�ָ������NULL
//        tail->next = pnew;   //�½ڵ���뵽��β
//        tail = pnew;         //βָ��ָ��ǰ��β�ڵ�
//    }
//    return head;  //���ش��������ͷָ��
//}
//
//
//
////�ڵ�i���ڵ㴦����һ���ڵ�
//void insert(NODE *head,NODE *pnew,int i)
//{
//    NODE *p; //��ǰָ��
//    //int j;
//    p = head ;
//    for (int j = 0 ; j < i && p != NULL; j++) //pָ��Ҫ����ĵ�i���ڵ�
//        p = p->next;
//    if(p == NULL)
//    {
//        printf("����Ľڵ㲻���ڣ�");
//        return ;
//    }
//    pnew->next = p->next;  //����ڵ��ָ����ָ���i���ڵ�ĺ�̽ڵ�
//    p->next = pnew;
//}
//
//void pdelete(NODE *head,int i )
//{
//    NODE *p,*q;
//    int  j ;
//    if(i == 0 ) // ɾ������ͷָ�룬����
//        return ;
//    p = head;
//    for(j = 1; j < i && p->next != NULL; j++)
//        p = p->next ; // ��pָ��Ҫɾ���ĵ�i���ڵ��ǰ���ڵ�
//    if(p->next == NULL)
//    {
//        printf("�����ڣ�");
//        return ;
//    }
//    q = p->next; //qָ���ɾ���Ľڵ�
//    p->next = q->next; //ɾ���ڵ�i��Ҳ��д��p->next = p->next->next
//    free(q); //�ͷŽڵ�i���ڴ浥Ԫ
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
///*����һ��ֻ��ͷ���Ŀ�����*/
//struct student* Create()
//{
//    struct student *head;
//    head = (struct student*)malloc(sizeof(struct student));
//    if(head == NULL)
//    {
//        printf("����ͷ���ʧ�ܣ�\n");
//        return NULL;
//    }
//    head->next = NULL;
//    return head;
//}
//
///*��sָ��Ľ���������ʹ���������򣬲�����ͷ���*/
//struct student *Insert(struct student *head,struct student *s)
//{
//    struct student *p = head;
//    while(p->next != NULL && s->score > p->next->score)
//    p = p->next;
//    if(p->next == NULL) //s->score �������
//    {
//         s->next = NULL;
//         p->next = s; //���ӽ��
//    }
//    else
//    {
//        s->next = p->next;
//        p->next = s; //���ӽ��q
//    }
//    return head;
//}
///*���ҷ��������Ľ�㣬������ָ��ý���ָ��*/
//struct student *search(struct student *head)
//{
//    struct student *p = head->next ;
//    int num ;
//    printf("������Ҫ����ѧ����ѧ�ţ�\n");
//    scanf("%d",&num);
//    while(p != NULL && p->num != num)
//        p = p->next;
//    if(p == NULL)
//    {
//        printf("�Ҳ����������Ľ�㣡��");
//        return NULL;
//    }
//    if(p->num == num)
//    {
//        printf("�ҵ����������Ľ��\n�ý��Ϊ%d\t%f",p->num,p->score);
//        return p;  //���ز��ҵ���ָ��
//    }
//}
///*������������ֵ��Ҳ�ƶ�����ı���*/
//void print(struct student *head)
//{
//    struct student *p;
//    printf("    �������£�\n");
//    p = head->next;
//    while(p != NULL)
//    {
//        printf("%d\t%.1f\n",p->num ,p->score);
//        p = p->next;
//    }
//}
///*�ͷ�����*/
//void free_list(struct student *head)
//{
//    struct student *p = head;
//    print("�ͷ�����\n");
//    while(p != NULL)
//    {
//        head = head->next ;
//        free(p);
//        p = head;
//    }
//    printf("�ͷ�����ɹ���\n");
//}
//
///*ɾ��������ֵΪnum�Ľ�㣬�������������ָ��*/
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
//        printf("�Ҳ�������ɾ��Ҫ��Ľ�㣡��\n");
//    }
//    if(p1->num == num_x)
//    {
//        p2->next = p1->next;
//        free(p1);
//        printf("���ɾ���ɹ���\n");
//    }
//    return head;
//}
//
///*��������ͷ��������������*/
//int main()
//{
//    struct student *p,*head;
//    char c ;
//    int num ;
//    float score;
//    printf("��ͷ��������������\n");
//    head = Create();
//    while(1)
//    {
//        printf("I:������(�Զ�����)  P:�������  S:���ҽ��  D:ɾ�����  E:�ͷ������˳�����!  ");
//        c=getch();
//		switch(c)
//		{
//			case'I':
//				printf("��ֱ�����Ҫ����ѧ����ѧ�źͷ���:\n");
//				scanf("%d%f",&num,&score);
//				p=(struct student*)malloc( sizeof(struct student) );
//				if(p==NULL)
//					{
//						printf("����ý��ʧ��!!!\n");
//						exit (0) ;
//					}
//				p->num=num;  p->score=score;   //��p��ֵ
//				Insert(head,p);
//				printf("����ɹ�!\n");
//				break;
//			case'P':
//				print(head);
//				break;
//			case'S':
//				search(head);
//				break;
//			case'D':
//				printf("������Ҫɾ����ѧ����ѧ��:\n");
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
//int n;                               /* n Ϊȫ�ֱ���������ͳ�ƽ��ĸ���*/
///*�D�D�D�D�D�D�D---�D�D�D�D-�D�D�Dcreat�����D�D�D�D�D�D----�D�D�D�D�D�D�D�D*/
//struct student *creat()                            /* ����creat�������ڽ�������*/
//{
//  struct student *head;
//  struct student *p1,*p2;
//  n=0;
//  p2=(struct student *)malloc(LEN);               /* ����һ����СΪLEN���ڴ浥Ԫ*/
//  p1=p2;
//  printf("������ѧ��:");scanf("%ld",&p1->num);             /* ����ѧ��*/
//  if(p1->num!=0)
//    { printf("������绰:");scanf("%f",&p1->tel);        /* ����绰����*/
//      printf("�������ַ:");scanf("%s",p1->add);          /* �����ַ*/
//      printf("�������ʱ�:");scanf("%ld",&p1->zip);         /* �����ʱ�*/
//      printf("ok! ��������һ��������Ϣ\n");          /* ��ʾ�Ѿ������һλͬѧ����Ϣ*/
//    }
//  head=NULL;
//  while(p1->num!=0)                      /* ��������ѧ�Ų���0���ռ������������ͬѧ����Ϣ*/
//    { n=n+1;
//      if(n==1) head=p1;
//      else p2->next=p1;
//      p2=p1;
//      p1=(struct student *)malloc(LEN);
//      printf("������ѧ��:");scanf("%ld",&p1->num);
//      if(p1->num!=0)
//        { printf("������绰:");scanf("%f",&p1->tel);
//          printf("�������ַ:");scanf("%s",p1->add);
//          printf("�������ʱ�:");scanf("%ld",&p1->zip);
//          printf("ok! ��������һ��������Ϣ\n");
//        }
//     }
//  p2->next=NULL;
//  return  head;                                    /* ����creat����*/
//}
///*�D�D�D�D�D�D�D---�D�D�D�D-�D�D�Dprint�����D�D�D�D�D�D----�D�D�D�D�D�D�D�D*/
//void print(struct student *head)                   /* ��ʼ��ӡ����*/
//{ struct student *p;
//  printf("\n Now,These %d records are:\n",n);
//  p=head;
//  if(head!=NULL)                                   /* ��������ǿգ����ӡÿ�������Ϣ*/
//    {    printf("-------------|------------ |-------------|--------\n");
//          printf("ѧ��        |�绰        |��ַ        |�ʱ�   \n");
//      do
//       { printf("-------------|------------ |-------------|--------\n");
//         printf("0%-12ld|%-13.0f|%-13s|%-13ld\n",p->num,p->tel,p->add,p->zip);
//         p=p->next;
//       }while(p!=NULL);
//         printf("-------------|------------ |-------------|--------\n");
//     }
//  else printf("�����ǿյ�!\n");                /* ��������ǿձ�����ʾ��������ǿձ�*/
//}                                                  /* ����print����*/
///*�D�D�D�D�D�D�D---�D�D�D�D---�D�D�Ddel�����D�D�D�D�D�D-----�D�D�D�D�D�D�D�D*/
//struct student *del(struct student *head,long num)           /* ��ʼ����del����������ɾ������*/
//{ struct student *p1,*p2;
//  if(head==NULL) {printf("\n�����ǿյ�!\n"); return head; }   /* ���ڼ�������Ƿ�Ϊ�գ����Ϊ�գ�����ʾ�������Ϊ�ձ�*/
//  p1=head;
//  while(num!=p1->num && p1->next!=NULL)
//    {p2=p1;p1=p1->next;}
//  if(num==p1->num)                                        /* �ҵ���Ӧ�Ľ��*/
//    { if(p1==head) head=p1->next;
//      else p2->next=p1->next;
//      printf("ɾ��:0%ld\n",num);
//      n=n-1;
//     }
//  else printf("0%ld û���ҵ�!\n",num);                       /* û�д򵽶�Ӧ�Ľ�㣬����ʾû���ҵ�*/
//  return head;
//}
///*�D�D�D�D�D�D�D---�D�D�D�D-�D�D�Dinsert�����D�D�D�D�D�D----�D�D�D�D�D�D�D�D*/
//struct student *insert(struct student *head,struct student *lnew)   /* ����insert���������ڲ����㣬����ֵΪһ��ָ��*/
//{ struct student *p0,*p1,*p2;
//  p1=head;
//  p0=lnew;
//  if(head==NULL)  {head=p0;p0->next=NULL;}   /* �������Ϊ�ձ��հѲ���Ľ��ָ���ͷָ�룬����nextΪ��*/
//  else
//      { while((p0->num>p1->num) && (p1->next!=NULL))       /* Ѱ�Ҹò����λ��*/
//          {p2=p1;
//           p1=p1->next;
//           }
//        if(p0->num<=p1->num)                              /* �ҵ��˸ò����λ��*/
//          {if(head==p1) head=p0;                                     /* ������ǰ��*/
//           else p2->next=p0;                                         /* ���嵽p1,p2֮��*/
//           p0->next=p1;
//           }
//        else {p1->next=p0;p0->next=NULL;}                              /* ���嵽���*/
//       }
//  n=n+1;
//  return head;                                                        /* �������*/
//}                                                                    /* ����insert�����Ľ���*/
///*�D�D�D�D�D�D�D---�D�D�D�D-�D�D�Dmenubar�����D�D�D�D�D�D----�D�D�D�D�D�D�D�D*/
//int menubar()                                                        /*�����˵�����*/
//{ int flag=1;                                                       /*�������Ǻ�*/
//  int c;                                                          /*�����洢ʹ����ѡ��Ĳ˵�����*/
//  printf("\n\n************** �����ۺϴ��� ****************\n");
//  printf("0:��������                                  ----\n");
//  printf("1:�������\n");
//  printf("2:������                                  �˵�\n");
//  printf("3:ɾ�����\n");
//  printf("4:�˳�                                      ----\n");
//  printf("*************************************************");
//  printf("\n���������ִ�е���������Ӧ��0~4����:");
//  scanf("%d",&c);                                                   /*����ʹ�ö�������Ĵ���*/
//  while(flag)         /*flag������ǣ����Ϊ����Ϊ�գ�����ʹ���ߵ�һ������Ĳ���0���߲���4������Ҫ��������*/
//    {if(n==0&&c!=0&&c!=4)
//      {printf("�ڽ�������֮ǰ�������뽨������\n");
//       printf("\n������0~4����:");
//       scanf("%d",&c);
//       flag=1;
//       }
//     else flag=0 ;
//    }
// while( c<0 || c>4 )                              /*��ʾ�����Ѿ�������������Ĳ��ܴ���4������С��0*/
//  { printf("\n������~4����:");
//    scanf("%d",&c);
//  }
//return c;                                             /*����c��ֵ*/
// }
///*�D�D�D�D�D�D�D---�D�D�D�D-�D�D�Dmain�����D�D�D�D�D�D----�D�D�D�D�D�D�D�D*/
//void main()                                              /*��ʼ������*/
//{
//    struct student *head,*lnew;
//    long del_num;
//    for(;;)                                                      /*��ʼforѭ��*/
//    {
//        switch (menubar())
//        { case 0:printf("�����봴��������Ľ�����Ϣ:\n");
//                 head=creat();
//                 break;
//          case 1:print(head);
//                 break;
//          case 2: printf("\n������Ҫ����Ľ�����Ϣ:\n");
//                 lnew=(struct student *)malloc(LEN);
//                 printf("������ѧ�ţ�");scanf("%ld",&lnew->num);
//                 if(lnew->num!=0)
//                   { printf("������绰:");scanf("%f",&lnew->tel);
//                     printf("�������ַ:");scanf("%s",lnew->add);
//                     printf("�������ʱ�:");scanf("%ld",&lnew->zip);
//                   }
//                 while(lnew->num!=0)
//                   { head=insert(head,lnew);
//                     print(head);
//                     printf("��������һ��Ҫ����Ľ�����Ϣ:\n");
//                     lnew=(struct student *)malloc(LEN);
//                     printf("������ѧ��:");scanf("%ld",&lnew->num);
//                     if(lnew->num!=0)
//                        { printf("������绰");scanf("%f",&lnew->tel);
//                          printf("�������ַ:");scanf("%s",lnew->add);
//                          printf("�������ʱ�:");scanf("%ld",&lnew->zip);
//                          printf("ok! ��������һ��Ҫ����Ľ�����Ϣ\n");
//					    }
//                    }
//                 break;
//         case 3:printf("\n����������ɾ���Ľ���ѧ��:");
//                scanf("%ld",&del_num);
//                while(del_num!=0)
//                { head=del(head,del_num);
//                  print(head);
//                  printf("\n����������ɾ���Ľ���ѧ��:");
//                 scanf("%ld",&del_num);
//                }
//                break;
//        case 4: system("CLS");
//                printf("лл����ʹ��\n\n\n\n");
//                getch();
//                exit(0);                                            /*�˳�forѭ��*/
//        }
//   }
//}                                                                   /*����������*/



