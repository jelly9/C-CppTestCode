Status CreateBiTree(BiTree &T) //先序创建二叉树
 {  
         char ch;
    scanf("%c",&ch);       
    if (ch=='#')
                   T=NULL; //表示某节点已经结束
    else {
                   T = (BiTNode *)malloc(sizeof(BiTNode));  //分配空间
      if (!T)
                     return ERROR;
      T->data = ch;              // 生成根结点
      CreateBiTree(T->lchild);   // 构造左子树
      CreateBiTree(T->rchild);   // 构造右子树
    }
    return OK; 
}
void PreOrderTraverse (BiTree T)// 先序遍历二叉树
{
   if (T)
   {
        printf("%c",T->data);
      PreOrderTraverse(T->lchild); // 遍历左子树
      PreOrderTraverse(T->rchild);// 遍历右子树
   }
} 
void InOrderTraverse (BiTree T)// 中序遍历二叉树
{
   if (T)
   {
      InOrderTraverse(T->lchild); // 遍历左子树
           printf("%c",T->data); 
   InOrderTraverse(T->rchild); // 遍历右子树
   }
}
void PostOrderTraverse(BiTree T) //后序遍历二叉树  左右根
{
   if (T)
   {
      PostOrderTraverse(T->lchild); // 遍历左子树 
      PostOrderTraverse(T->rchild);  // 遍历右子树
           printf("%c",T->data);
   }
}
Status InitStack(SqStack &S)//构造一个空栈
{
         S=(SqStack)malloc(sizeof(LNode));
         if(!S)
                   return ERROR;
         S->next=NULL;
         return OK;
}
Status StackEmpty(SqStack S)//栈判空
{
         if (S->next==NULL)
                   printf("\n这是一个空链表！");
         else 
         {
         printf("\n这不是一个空链表！");
    return ERROR;
         }
         return OK;
}
Status Push(SqStack &S,BiTree T)
{
         SqStack p;
         p=(SqStack)malloc(sizeof(LNode)); 
if(!S||!p) return ERROR;
         p->data=T;
    p->next=S;
    S=p;
         return OK;
}
Status Pop(SqStack &S,BiTree &e)   //出栈
{
         SqStack p;
         if (S==NULL) return ERROR;
     else
          {
                    p=S;
                    S=p->next;
                    e=p->data;
         free(p);       
      }
          return OK;
}
Status GetTop(SqStack S,BiTree T) //取栈顶元素
{
         SqStack p;
      p=(SqStack)malloc(sizeof(LNode));
         if(!p)
                   return ERROR;
    while(p->next!=NULL)
         {
                   p=p->next;
         }
         T=p->data;
    return OK;  
}
//队列操作
Status  InitQueue(LinkQueue &Q) 
{
          Q.front =Q.rear=(QueuePtr)malloc(sizeof(QNode));
         if (!Q.front)
                   return ERROR;                  
         Q.front->next = NULL;
         return OK;
}
Status  EnQueue(LinkQueue &Q,BiTree e)
{
         QueuePtr p;
         p=(QueuePtr)malloc(sizeof (QNode));
         if(!p)  
                   return ERROR;  
         p->data=e; 
         p->next=NULL;
         Q.rear->next = p;  
         Q.rear=p;
         return OK;
}
Status  QueueEmpty(LinkQueue &Q)
{
         if(Q.front->next==NULL)
                   return OK;
         return ERROR;
}                
Status  DeQueue(LinkQueue &Q,BiTree &e)
{
         QueuePtr p;
         if (Q.front == Q.rear)  
                   return ERROR;
         p = Q.front->next; 
         e = p->data;
         Q.front->next = p->next;
         if (Q.rear == p)
                   Q.rear = Q.front; 
         free (p);     
         return OK;
}
 void LevelOrder(BiTree T)//按层次遍历二叉树T， Q为队列
{
     BiTree b=NULL;
          LinkQueue Q;
          InitQueue(Q);                 
          if (T!=NULL)
          {                                
                    EnQueue(Q,T);                                      
                    while (!QueueEmpty(Q))
                    {              
           DeQueue(Q,b);                     
                            printf("%c",b->data);        
                     if (b->lchild!=NULL)
                                     EnQueue(Q,b->lchild);//左子树非空，则入队列
                     if (b->rchild!=NULL)
                                     EnQueue(Q,b->rchild);//右子树非空，则入队列
                    }
          }//if
}
Status Depth (BiTree T) // 返回二叉树的深度  节点数之和
{ 
   int depthval,depthLeft,depthRight;
   if (!T) 
            depthval = 0;
   else  
   {
      depthLeft = Depth( T->lchild );  //返回值为depthval
      depthRight= Depth( T->rchild );
      depthval = 1 + (depthLeft > depthRight ?depthLeft : depthRight);
   }
   return depthval; 
}
Status countLeaf(BiTree T) //.统计叶子节点的数目
 { 
         int num1,num2,num;    
         if (T==NULL)
                   num=0;
         else
                     if((T->lchild==NULL)&&(T->rchild==NULL))
                              num=1;  //节点组成
                     else
                     {
                              num1=countLeaf(T->lchild);
                              num2= countLeaf(T->rchild);
                              num= num1+num2;
                     }
         return num;
}
Status CountSingle(BiTree T) //统计单分支结点
{
         int num1,num2,num; //num1左单结点num2右单结点   
         if (T==NULL)       //跳出条件
                   num=0;
         else
         {
                   if((T->lchild != NULL)&&(T->rchild == NULL)) //该结点只有左孩子
                   {
                            num1=1;
                            num2=0;
                            num=num1+CountSingle(T->lchild);
                            //num=CountSingle(T->lchild);
                   }
                   if((T->lchild == NULL)&&(T->rchild != NULL)) //该结点只有右孩子
                   {
                            num1=0;
                            num2=1;
                            num=CountSingle(T->rchild)+num2;      
                            //num=CountSingle(T->rchild); 
         }
                   if((T->lchild == NULL)&&(T->rchild == NULL))//该结点为叶子结点
                   {
                            num1=0;
                            num2=0;
                            num=0;
                   }
                   if((T->lchild != NULL)&&(T->rchild != NULL)) //该结点为满
                   {
                            num1=CountSingle(T->lchild);
                            num2=CountSingle(T->rchild);
                            num=num1+num2;
                   }                
         }
         return num;
}
Status CountDouble(BiTree T)  //统计双分支结点
{
         int num;  
         if (T==NULL)  //跳出条件
                   num=0;
         else
         {
                   if((T->lchild != NULL)&&(T->rchild == NULL))//该结点只有左孩子
                            num=CountDouble(T->lchild);
                   if((T->lchild == NULL)&&(T->rchild != NULL))//该结点只有右孩子
                            num=CountDouble(T->rchild);
                   if((T->lchild == NULL)&&(T->rchild == NULL))//该结点为根结点  //***
                            num=0;
                   if((T->lchild != NULL)&&(T->rchild != NULL))//该结点为满
                   {
                            num=CountDouble(T->lchild)+CountDouble(T->rchild)+1;
                   }                
         }
         return num;
}
int countsingle(BiTree T)//计算单分支节点数 
{
         if(T==NULL)
                   return 0;
         else
                   if((T->lchild==NULL)&&(T->rchild==NULL))
                            return 0;//左右均为空
                   else
                   {
                            if(!T->lchild && T->rchild)//左空又不空，则递归计算右边
                                     return countsingle(T->rchild)+1;
                            else
                            {
                                     if(T->lchild&&!T->rchild)//左不空右空，递归计算左子树
                                               return countsingle(T->lchild)+1;
                                     else //左右均不空，则相加
                                               return countsingle(T->rchild)+countsingle(T->lchild);
                            }
                   }
}
 int Count_Double(BiTree T)
 {
         //统计双分支结点的数目
         if (T==NULL)
                   return 0;//空树
         else if (T->lchild==NULL && T->rchild==NULL)
                   return 0;//叶子结点
         else{         
                   if (!T->lchild && T->rchild)
                            return Count_Double(T->rchild);//只有左单分支
                   if (T->lchild  && !T->rchild)
                            return Count_Double(T->lchild);//只有右单分支
                   if (T->lchild && T->rchild)
                            return Count_Double(T->lchild)+Count_Double(T->rchild)+1;//双分支结点         
         }
         return Count_Double(T); 
}      
void change_left_right(BiTree T)
{  
         BiTree temp;         
         if (T)
         {
                      change_left_right(T->lchild);
                      change_left_right(T->rchild);
                      temp=T->lchild;
                      T->lchild =T->rchild;
                      T->rchild=temp; 
                   }
}
Status Insert(BiTree &T,char x)
{  
   if (T==NULL)
   {
           T=(BiTree)malloc(sizeof(BiTNode));
      T->data=x;
      T->lchild=T->rchild=NULL;
   }
   else{
               if (x<T->data) Insert(T->lchild,x);
               if (x>T->data) Insert(T->rchild,x);
        }
   return OK;
}  
void CreateSBiTree(BiTree &T)
{
    char x;
    T=NULL;
         printf("请插入字符：\n");
         scanf("%c",&x);
    while (x!='@')
         {
        Insert(T,x); 
                    scanf("%c",&x);
    }
}
Status InOrderTraverse(BiTree T)
{//中序遍历非递归算法,s为存储二叉树结点指针栈
         SqStack S;
         BiTree p;
    InitStack(S);
    p=T;
         while (p||!StackEmpty(S)) 
         {
                   if (p){ Push(S,p); 
               p=p->lchild;}//根指针进站，遍历左子树
                            else
                            {
                                     Pop(S,p);              
                                     cout<<p->data; 
                                     p=p->rchild;
                            }
         }
         return OK;
}

