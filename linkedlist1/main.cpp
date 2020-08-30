#include <iostream>

using namespace std;

class node
{
    public:
    int info;
    node *next;

};

node *create()
{
	char ch;
	int v;
	node *s,*p;
	p=(node *) malloc(sizeof(node));
	/*if(p==NULL)
	{
		printf("Memory full. Cannot create list.");
		exit(0);
	}*/
	s=p;
	do
	{
		cout<<"Enter node info :";
		cin>>v;
		p->info=v;
		p->next=NULL;
		fflush(stdin);
		cout<<"Continue?";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		{
			p->next=(node *) malloc(sizeof(node));
			/*if(p->next==NULL)
			{
				cout<<"Memory full. Cannot create list.";
				exit(0);
			}*/
			p=p->next;
		}
	}while(ch=='y'||ch=='Y');
	//p->next=s;
	return(s);
}
void disp(node *p)
{
	while(p!=NULL)
	{
		if(p->next==NULL)
			cout<<p->info<<" ";
		else
			cout<<p->info<<" ";
		p=p->next;
	}
}
node *insertbeg(node *s,int v)
{

    node *nw=(node *)malloc(sizeof(node));
    nw->info=v;
    nw->next=s;
    s=nw;
    return(s);

}
node *insertlast(node *s,int v)
{
    node *p;
    node * nw=(node *)malloc(sizeof(node));
    nw->info=v;
    nw->next=NULL;
    if(s==NULL)
    {
        s=nw;
    }
    p=s;
    while(p->next!=NULL)
        p=p->next;
    p->next=nw;
    return(s);
}
node *insertposition(node *s,int v,int k)
{
        node *p=s,*nw,*n;
        int i;
        nw=(node *)malloc(sizeof(node));
        nw->info=v;
        nw->next=NULL;
        if(k==1)
        {
            n=insertbeg(s,v);
            return n;
        }
        for(i=1;(i<k-1 && p!=NULL);i++)
            p=p->next;
        nw->next=p->next;
        p->next=nw;
        return(s);
}
node *delfirst(node *s)
{
    node *p=s;
    s=s->next;
    free(p);
    return(s);
}
node *dellast(node * s)
{
    node *t,*p;
    p=s;
    if(p->next==NULL)
    {
       t=p;
    }
    while(p->next->next!=NULL)
        p=p->next;
    t=p->next;
    p->next=NULL;
    free(t);
    return s;
}
node * deletepos(node *s,int k)
{
    node *p,*t;
    p=s;
    if(k==1)
    {
       s=s->next;
    }
    for(int i=1;i<k-1 && p!=NULL;i++)
    {
        p=p->next;
    }
    t=p->next;
    p->next=t->next;
    free(t);

    return(s);
}
node *insertbefore(node *s,int v,int val)
{
    node *nw,*p;
    nw=(node *)malloc(sizeof(node));
    nw->info=v;
    nw->next=NULL;
    p=s;
    while(p->next!=NULL)
    {
        if(p->next->info==val)
            break;
        p=p->next;
    }
    nw->next=p->next;
    p->next=nw;
    return(s);

}
void searchll(node *s,int x)
{
    node *p;
    p=s;
    int counts=0;
    while(p!=NULL)
    {
        if(p->info==x){
                break;}
        counts++;
        p=p->next;
    }
    if(p==NULL)
        cout<<"not found in the linked list";
    else
        cout<<"found in "<<counts+1<<" position";
}
void countnode(node *s)
{
    node *p=s;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    cout<<"total no of node are:"<<c;
}
void middlenode(node *s)
{
	node *fp=s;
	node *sp=s;
	node *prev;
	if(s!=NULL)
	{
		while(fp!=NULL && fp->next!=NULL)
		{
			fp=fp->next->next;
			prev=sp;
			sp=sp->next;
		}
		if(fp==NULL)
			cout<<"The middle element is "<<prev->info<<"and"<<sp->info;
		else
			cout<<"The middle element is:"<<sp->info;
	}
}
void maxelement(node *s)
{
    int maxm=INT_MIN;
    node *p=s;
    while(p!=NULL)
    {
        if(p->info>maxm)
            maxm=p->info;
        p=p->next;
    }
    cout<<"maximum element is:"<<maxm;
}
node *reversell(node *s)
{
    node *p,*q,*r;
    p=s;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    s=q;
    return(s);
}
void checkloop(node *s)
{
    node *sp,*fp,*prev;
    sp=s;
    fp=s;
    int flag=0;
    while(fp!=NULL && fp->next!=NULL)
    {
        fp=fp->next->next;
        prev=sp;
        sp=sp->next;
        if(sp==fp)
       {
          flag=1;
          break;

        }
    }

    if(flag==1)
    {
        cout<<"looping is present";
    }
    else
    {
        cout<<"lopping not present";
    }
}
node *insertsorted(node *s,int v)
{
    node *p=s,*q;
    node *nw=(node *)malloc(sizeof(node));
    nw->info=v;
    nw->next=NULL;

    while(p && p->info<v)
    {
        q=p;
        p=p->next;

    }

    cout<<"yes";
    nw->next=q->next;
    q->next=nw;

    return(s);

}
void sortll(node *s)
{
    node *p,*q;
    int t;
    for(p=s;p->next!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(p->info>q->info)
            {
                t=p->info;
                p->info=q->info;
                q->info=t;
            }
        }
    }

}
void removeduplicate(node *s)
{
    node *p=s,*prev,*t;
    int a[100]={0};
    while(p!=NULL)
    {
        if(a[p->info]!=0)
        {
            t=prev->next;
            prev->next=p->next;
            free(t);
            p=prev->next;
            continue;
        }
        else
            a[p->info]=p->info;
        prev=p;
        p=p->next;
    }
}
void nthnodehead(node *s,int k)
{
    node *p=s;
    int i;
    for(int i=1;i<k && p!=NULL;i++)
    {
        p=p->next;
    }
    cout<<"element at "<<k<<" position is "<<p->info;
}
void nthnodeending(node *s,int k)
{
    node *one,*two;
    one=s;
    two=s;
    int n=k;
    while(n--)
    {
        two=two->next;
    }
    while(two!=NULL)
    {
        one=one->next;
        two=two->next;
    }
    cout<<k<<"th"<<" element from end is "<<one->info<<endl;
}

node *deletenthnodefromending(node *s,int k)
{
    node *one,*two,*prev,*t;
    one=s;
    two=s;
    int n=k;
    while(n--)
    {
        two=two->next;
    }
    while(two!=NULL)
    {
        prev=one;
        one=one->next;
        two=two->next;
    }
    t=prev->next;
    prev->next=t->next;
    free(t);
    return(s);
}
void checkpallindrome(node *s)
{
    node *p,*q,*fs,*ss;
    p=s;
    q=s;
//splitting into two linked list
    if(p->next==NULL)
    {
        cout<<"it is pallindome"<<endl;  //for a single node
    }
    while(1)
    {

        p=p->next->next;
        if(p==NULL)   //in case of even no of nodes
        {

            ss=q->next;
            break;
        }
        if(p->next==NULL) //in case of odd no of linked list
        {


            ss=q->next->next;
            break;
        }
        q=q->next;
    }

    q->next=NULL;
    ss=reversell(ss);
    fs=s;
    while(fs!=NULL && ss!=NULL)
    {

        if(fs->info==ss->info)
        {
            fs=fs->next;
            ss=ss->next;
        }
        else
        {
            cout<<"not a pallindome";
            return;
        }
    }
    cout<<"it is a palindrome";
}
void splitfrommiddle(node *s,node **h1,node **h2)
{
    node *sp,*fp,*prev;
    fp=s;
    sp=s;
 if(s!=NULL)
{
    while(fp!=NULL && fp->next!=NULL)
    {
        fp=fp->next->next;
        prev=sp;
        sp=sp->next;

    }
    if(fp==NULL)
    {
        *h2=sp;
        prev->next=NULL;
        *h1=s;
    }
    else
    {
        *h2=sp->next;
        sp->next=NULL;
        *h1=s;
    }
}
}
node  *mergesortedll(node *l1,node *l2)
{
    node *finalhead,*finaltail;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    finalhead==NULL;
    if(l1->info<l2->info)
    {
        finalhead=l1;
        l1=l1->next;
    }
    else
    {
        finalhead=l2;
        l2=l2->next;
    }
    finaltail=finalhead;  //initially  tail of final linked list is same as final head
    while(l1 && l2)
    {
        if(l1->info<l2->info)
        {
            finaltail->next=l1;
            l1=l1->next;
        }
        else
        {
            finaltail->next=l2;
            l2=l2->next;
        }
        finaltail=finaltail->next;
    }
    if(l1)
        finaltail->next=l1;
    else
        finaltail->next=l2;
    return finalhead;
}
node *splitfrommiddle1(node *s)
{

    node *st2,*fp,*sp,*prev,*st1;
    fp=s;
    sp=s;
    if(s==NULL || s->next==NULL)
        return s;



    if(s!=NULL)
{
    while(fp!=NULL && fp->next!=NULL)
    {
        fp=fp->next->next;
        prev=sp;
        sp=sp->next;

    }
    if(fp==NULL)
    {
        st2=prev->next;
        prev->next=NULL;
        st1=s;

    }
    else
    {
        st2=sp->next;
        sp->next=NULL;
        st1=s;

    }
    //disp(st1);   for printing the first
    cout<<endl;
    //disp(st2);
    return st2;
}
}
node *mergesort(node *s)
{
    node *start1,*start2,*startM;
    if(s==NULL || s->next==NULL)
    {
        return s;
    }
    start1=s;
    start2=splitfrommiddle1(s);
    start1=mergesort(start1);
    start2=mergesort(start2);
    startM=mergesortedll(start1,start2);
    disp(startM);
    return startM;

}

int main()
{
   node *st,*s1,*s2,*l1,*l2,*l3;
   node **st1=&s1,**st2=&s2;
   int v,c,pos,val;
   do
   {
       cout<<"\nmenu"<<endl;
       cout<<"----------------------------"<<endl;
       cout<<"1.create linked list"<<endl;
       cout<<"2.display"<<endl;
       cout<<"3.insert at beginning"<<endl;
       cout<<"4.insert at last"<<endl;
       cout<<"5.insert at position:"<<endl;
       cout<<"6.delete at beginning"<<endl;
       cout<<"7.delete last"<<endl;
       cout<<"8.delete at position"<<endl;
       cout<<"9.insert before:"<<endl;
       cout<<"10.searching the node"<<endl;
       cout<<"11.counting the node"<<endl;
       cout<<"12.middle node"<<endl;
       cout<<"13.reverse the linked list"<<endl;
       cout<<"14.Maximum element"<<endl;
       cout<<"15.insert in a sorted list"<<endl;
       cout<<"16:sort the linked list"<<endl;
       cout<<"17:check looping"<<endl;
       cout<<"18.remove duplicate element"<<endl;
       cout<<"19.nth element from starting"<<endl;
       cout<<"20.nth element from end"<<endl;
       cout<<"21.delete nth node from end"<<endl;
       cout<<"22.check pallindrome"<<endl;
       cout<<"23.split from middle"<<endl;
       cout<<"24.merge two sorted linked list"<<endl;
       cout<<"25.split from middle 2nd type(better type)"<<endl;//used in merge sort of linked list
       cout<<"26.merge sort in linked list"<<endl;
       cout<<"27.exit"<<endl;
       cout<<" enter ur choice:"<<endl;
       cin>>c;
       switch(c)
       {
       case 1:
                st=create();
                break;
       case 2:
                disp(st);
                break;
       case 3:
                cout<<"insert the no:";
                cin>>v;
                st=insertbeg(st,v);
                break;
       case 4:
                cout<<"insert the no:";
                cin>>v;
                st=insertlast(st,v);
                break;

       case 5:
                cout<<"insert the no and its position:";
                cin>>v>>pos;
                st=insertposition(st,v,pos);
                break;
       case 6:
                st=delfirst(st);
                break;
       case 7:
                st=dellast(st);
                break;
       case 8:
                cout<<"enter the position to delete:"<<endl;
                cin>>pos;
                st=deletepos(st,pos);
                break;
       case 9:
                cout<<"enter the value and before  to insert:"<<endl;
                cin>>v>>val;
                st=insertbefore(st,v,val);
                break;
       case 10:
                cout<<"enter the no to be searched:";
                cin>>v;
                searchll(st,v);
                break;
       case 11:
                countnode(st);
                break;
       case 12:
                middlenode(st);
                break;
       case 13:
                st=reversell(st);
                break;
       case 14:
                maxelement(st);
                break;
       case 15:
                cout<<"element to inserted:";
                cin>>v;
                cout<<"good";
                st=insertsorted(st,v);
                break;
       case 16:
                sortll(st);
                break;
       case 17:
                checkloop(st);
                break;
       case 18:
                removeduplicate(st);
                break;
       case 19:
                cout<<"enter the element from beginning:";
                cin>>pos;
                nthnodehead(st,pos);
                break;
       case 20:
                cout<<"enter the element from end:";
                cin>>pos;
                nthnodeending(st,pos);
                break;
       case 21:
                cout<<"enter the element from end:";
                cin>>pos;
                st=deletenthnodefromending(st,pos);
                break;
       case 22:
                cout<<"good"<<endl;
                checkpallindrome(st);
                break;
       case 23:
                splitfrommiddle(st,st1,st2);
                disp(*st1);
                cout<<endl;
                disp(*st2);
                break;
       case 24:
                cout<<"enter value in first linked list:"<<endl;
                l1=create();
                cout<<"enter value in second linked list:"<<endl;;
                l2=create();
                l3=mergesortedll(l1,l2);
                cout<<"merged list is:";
                disp(l3);
                break;
       case 25:
                st=splitfrommiddle1(st);
                break;
       case 26:
                st=mergesort(st);
                break;

       case 27:
                cout<<"leaving.........."<<endl;
                break;
       }
   }while(c!=27);
   return 0;
}
