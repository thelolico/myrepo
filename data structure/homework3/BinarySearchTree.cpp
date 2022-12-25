#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
class BinarySearchTree;

class TreeNode{
private:
	long long int ID;
	char gender;
	long long int phone;
    TreeNode *RChild;
    TreeNode *LChild;
public:
    TreeNode():ID(0),gender(0),phone(0),RChild(0),LChild(0){};
    TreeNode(long long int key,char value2,long long int value3):ID(key),gender(value2),phone(value3),RChild(0),LChild(0){};

    friend class BinarySearchTree;
};

class BinarySearchTree{
public:
    TreeNode *root;
	int deeply = 0;
	int times = 0;
	
    BinarySearchTree():root(0){};
    void insert(long long int key,char value2,long long int value3);
    void print_LVR(TreeNode *current);
    void print_VLR(TreeNode *current);
    bool search(long long int key,bool Judgment_mode);//exist is false,not exist is true
    void deep(TreeNode *current);//write in 'deeply'
    int FindNodeDeep(long long int key);
    void deleteTree(TreeNode *current);
    void write_out(TreeNode *current);
    int make_up_zero(long long int key);
};

int main()
{
	long long int ID;
	char gender;
	long long int phone;
	BinarySearchTree BST;
	
	ifstream closetimes;
    closetimes.open("CloseTimes.txt");
    int times;
    closetimes>>times;
    BST.times = times;
	if(times == 0){
		ofstream coutfile;
		coutfile.open("outputdata1.txt",ios::trunc);
		coutfile.close();
		ofstream s;
		s.open("output_search1.txt",ios::trunc);
		s.close();
		ifstream cinfile;
	    cinfile.open("inputdata1.txt");
		
			/*install*/
		for(int i = 0;i < 12;i++){
			cinfile>>ID>>gender>>phone;
			if(BST.search(ID,true)){
				BST.insert(ID,gender,phone);
			}
			else{
				cout<<"ID ";
				for(int m = 0;m < BST.make_up_zero(ID);m++){
					cout<<0;
				}
				cout<<ID<<" dose exist."<<endl;
				int s = 0;
				while(BST.search(100000 + s,true) == 0){
					s++;
				}
				BST.insert(100000 + s,'T',8862222222);
				cout<<"So we input:"<<100000+s<<","<<"T"<<","<<8862222222<<endl;
			}
		}
		cinfile.close();
		
//		cout<<"LVR: "<<endl;
//		BST.print_LVR(BST.root);
//		cout<<endl;
//		
//		cout<<"VLR: "<<endl;
//		BST.print_VLR(BST.root); 
//		cout<<endl;
		
		ifstream searchs;
    	searchs.open("wellsearch1.txt");
		for(int i = 0;i < 5;i++){
			int j;
			searchs>>j;
			BST.search(j,false);
		}
		searchs.close();
		cout<<endl;
	
		BST.deep(BST.root);
		cout<<"Deep: "<<BST.deeply<<endl;
		ofstream deepfile;
    	deepfile.open("FrontDeep.txt",ios::trunc);
    	deepfile<<BST.deeply;
    	deepfile.close();
		
		BST.write_out(BST.root);
		cout<<"Write tree to outputdata1."<<endl;
		
		BST.deleteTree(BST.root);
		cout<<"Delete tree success.";
		
    	ofstream closetimes;
    	closetimes.open("CloseTimes.txt",ios::trunc);
    	closetimes<<1;
	}
	else if(times == 1){
		ofstream s;
		s.open("output_search2.txt",ios::trunc);
		s.close();
		ofstream lvr;
		lvr.open("LVR_1.txt",ios::trunc);
		lvr.close();
		ofstream vlr;
		vlr.open("VLR_1.txt",ios::trunc);
		vlr.close();
		ofstream coutfile;
		coutfile.open("outputdata2.txt",ios::trunc);
		coutfile.close();
		ifstream cinfile;
	    cinfile.open("outputdata1.txt");
		
			/*install*/
		for(int i = 0;i < 12;i++){
			cinfile>>ID>>gender>>phone;
			if(BST.search(ID,true)){
				BST.insert(ID,gender,phone);
			}
			else{
				cout<<"ID ";
				for(int m = 0;m < BST.make_up_zero(ID);m++){
					cout<<0;
				}
				cout<<ID<<" dose exist."<<endl;
				int s = 0;
				while(BST.search(100000 + s,true) == 0){
					s++;
				}
				BST.insert(100000 + s,'T',8862222222);
				cout<<"So we input:"<<100000+s<<","<<"T"<<","<<8862222222<<endl;
			}
		}
		cinfile.close();
		
		cout<<"LVR: "<<endl;
		BST.print_LVR(BST.root);
		cout<<endl;
		
		cout<<"VLR: "<<endl;
		BST.print_VLR(BST.root); 
		cout<<endl;
		
		BST.deep(BST.root);
		cout<<"Deep: "<<BST.deeply<<endl;
		ifstream deepfile;
    	deepfile.open("FrontDeep.txt");
    	
    	int a;
    	deepfile>>a;
		if(a > BST.deeply){ cout<<"Front high:"<<a<<" Now short:"<<BST.deeply<<endl;}
		else if(a < BST.deeply){ cout<<"Front short:"<<a<<" Now high:"<<BST.deeply<<endl;}
		else{ cout<<"Front:"<<a<<" and Now:"<<BST.deeply<<" same"<<endl;}
		deepfile.close();

		ifstream cinfile2;
	    cinfile2.open("inputdata2.txt");
		
			/*install*/
		for(int i = 0;i < 12;i++){
			cinfile2>>ID>>gender>>phone;
			if(BST.search(ID,true)){
				BST.insert(ID,gender,phone);
			}
			else{
				cout<<"ID ";
				for(int m = 0;m < BST.make_up_zero(ID);m++){
					cout<<0;
				}
				cout<<ID<<" dose exist."<<endl;
				int s = 0;
				while(BST.search(100000 + s,true) == 0){
					s++;
				}
				BST.insert(100000 + s,'T',8862222222);
				cout<<"So we input:"<<100000+s<<","<<"T"<<","<<8862222222<<endl<<endl;
			}
		}
		cinfile2.close();
		
		ifstream searchs;
    	searchs.open("wellsearch2.txt");
    	//cout<<"Search: "<<endl;
		for(int i = 0;i < 5;i++){
			int j;
			searchs>>j;
			BST.search(j,false);
		}
		searchs.close();
		cout<<endl;
		
		BST.deep(BST.root);
		cout<<"Deep: "<<BST.deeply<<endl;
		ofstream frontdeep;
    	frontdeep.open("FrontDeep.txt",ios::trunc);
    	frontdeep<<BST.deeply;
    	frontdeep.close();
		
		BST.write_out(BST.root);
		cout<<"Write tree to outputdata2."<<endl;
		
		BST.deleteTree(BST.root);
		cout<<"Delete tree success.";
		
		ofstream closetimes;
    	closetimes.open("CloseTimes.txt",ios::trunc);
    	closetimes<<2;
    	closetimes.close();
	}
	else if(times == 2){
		ofstream lvr;
		lvr.open("LVR_2.txt",ios::trunc);
		lvr.close();
		ofstream vlr;
		vlr.open("VLR_2.txt",ios::trunc);
		vlr.close();
		
		ifstream cinfile;
	    cinfile.open("outputdata2.txt");
		
			/*install*/
		for(int i = 0;i < 24;i++){
			cinfile>>ID>>gender>>phone;
			if(BST.search(ID,true)){
				BST.insert(ID,gender,phone);
			}
			else{
				cout<<endl<<"ID ";
				for(int m = 0;m < BST.make_up_zero(ID);m++){
					cout<<0;
				}
				cout<<ID<<" dose exist."<<endl;
				int s = 0;
				while(BST.search(100000 + s,true) == 0){
					s++;
				}
				BST.insert(100000 + s,'T',8862222222);
				cout<<"So we input:"<<100000+s<<","<<"T"<<","<<8862222222<<endl;
			}
		}
		cinfile.close();
		
		cout<<"LVR: "<<endl;
		BST.print_LVR(BST.root);
		cout<<endl;
		
		cout<<"VLR: "<<endl;
		BST.print_VLR(BST.root); 
		cout<<endl;
		
		BST.deep(BST.root);
		cout<<"Deep: "<<BST.deeply<<endl;
		ifstream deepfile;
    	deepfile.open("FrontDeep.txt");
    	
    	int a;
    	deepfile>>a;
		if(a > BST.deeply){ cout<<"Front high:"<<a<<" Now short:"<<BST.deeply<<endl;}
		else if(a < BST.deeply){ cout<<"Front short:"<<a<<" Now high:"<<BST.deeply<<endl;}
		else{ cout<<"Front:"<<a<<" and Now:"<<BST.deeply<<" same"<<endl;}
		deepfile.close();
		
		ofstream closetimes;
    	closetimes.open("CloseTimes.txt",ios::trunc);
    	closetimes<<0;
	}else{
		cout<<"Don't rewrite CloseTimes.txt !"<<endl;
		ofstream closetimes;
    	closetimes.open("CloseTimes.txt",ios::trunc);
    	closetimes<<0;
    	cout<<"Reset to zero.";
	}

	return 0;
}

void BinarySearchTree::insert(long long int key,char value2,long long int value3)
{
	TreeNode *new_node = new TreeNode(key,value2,value3);

	if(root == 0) {
		root = new_node;
		return;
	}
	
	TreeNode *current = root;
	while(1){
		
		if(current->ID > key){
			if(current->LChild == NULL){
				current->LChild = new_node;
				//cout<<"laa"<<endl; 
				return;
			}
			current = current->LChild;
			//cout<<"L"<<endl;
		}
		else if(current->ID < key){
			if(current->RChild == NULL){
				current->RChild = new_node;
				//cout<<"raa"<<endl; 
				return;
			}
			current = current->RChild;
			//cout<<"R"<<endl;
		}
		else{
			cout<<"ERROR!"<<endl;
			return;
		}
	}
	
	return;
}

void BinarySearchTree::print_LVR(TreeNode *current){
	if(current){
		print_LVR(current->LChild);
//		for(int m = 0;m < make_up_zero(current->ID);m++){
//			cout<<0;
//		}
//		cout<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
		if(times == 1){
				ofstream lvr;
		    	lvr.open("LVR_1.txt",ios::app);
		    	for(int m = 0;m < make_up_zero(current->ID);m++){ lvr<<0;}
		    	lvr<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
		    	lvr.close();
			}else if(times == 2){
				ofstream lvr;
		    	lvr.open("LVR_2.txt",ios::app);
		    	for(int m = 0;m < make_up_zero(current->ID);m++){ lvr<<0;}
		    	lvr<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
		    	lvr.close();
			}
		print_LVR(current->RChild);
	}
	
}

void BinarySearchTree::print_VLR(TreeNode *current){
	if(current){
		if(times == 1){
				ofstream vlr;
		    	vlr.open("VLR_1.txt",ios::app);
		    	for(int m = 0;m < make_up_zero(current->ID);m++){ vlr<<0;}
		    	vlr<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
		    	vlr.close();
			}else if(times == 2){
				ofstream vlr;
		    	vlr.open("VLR_2.txt",ios::app);
		    	for(int m = 0;m < make_up_zero(current->ID);m++){ vlr<<0;}
		    	vlr<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
		    	vlr.close();
			}
		print_VLR(current->LChild);
		print_VLR(current->RChild);
	}
}

bool BinarySearchTree::search(long long int key,bool Judgment_mode){
	if(root == 0) {
		if(Judgment_mode == 0){
			if(times == 0){
				ofstream search_coutfile;
		    	search_coutfile.open("output_search1.txt",ios::app);
		    	search_coutfile<<"This ID does not exist."<<endl;
		    	search_coutfile.close();
			}else if(times == 1){
				ofstream search_coutfile;
				search_coutfile.open("output_search2.txt",ios::app);
		    	search_coutfile<<"This ID does not exist."<<endl;
		    	search_coutfile.close();
			}
			
			//cout<<"This ID does not exist."<<endl;
		}
		return 1;
	}
	
	TreeNode *current = root;
	while(1){
		
		if(current->ID > key){
			current = current->LChild;
		}
		else if(current->ID < key){
			current = current->RChild;
		}
		else{
			if(Judgment_mode == 0){
				if(times == 0){
					ofstream search_coutfile;
		    		search_coutfile.open("output_search1.txt",ios::app);
		    		for(int m = 0;m < make_up_zero(current->ID);m++){ search_coutfile<<0;}
		    		search_coutfile<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
		    		search_coutfile.close();
				}else if(times == 1){
					ofstream search_coutfile;
		    		search_coutfile.open("output_search2.txt",ios::app);
		    		for(int m = 0;m < make_up_zero(current->ID);m++){ search_coutfile<<0;}
		    		search_coutfile<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
		    		search_coutfile.close();
				}
				
				
//				for(int m = 0;m < make_up_zero(current->ID);m++){ cout<<0;}
//				cout<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
			}
			return 0;
		}
		
		if(current == NULL){
			if(Judgment_mode == 0){
				if(times == 0){
					ofstream search_coutfile;
		    		search_coutfile.open("output_search1.txt",ios::app);
		    		search_coutfile<<"This ID does not exist."<<endl;
		    		search_coutfile.close();
				}else if(times == 1){
					ofstream search_coutfile;
		    		search_coutfile.open("output_search2.txt",ios::app);
		    		search_coutfile<<"This ID does not exist."<<endl;
		    		search_coutfile.close();
				}
				
				//cout<<"This ID does not exist."<<endl;
			}
			return 1;
		}
	}

}

void BinarySearchTree::deep(TreeNode *current){
	if(current){
		if(current->RChild == NULL && current->LChild == NULL){
			int count = FindNodeDeep(current->ID);
			if(count > deeply){ deeply = count;}
		}
		deep(current->LChild);
		deep(current->RChild);
	}
}

int BinarySearchTree::FindNodeDeep(long long int key){
	if(root == 0) {
		return 0;
	}
	
	TreeNode *current = root;
	int count = 0;
	while(1){
		
		if(current->ID > key){
			current = current->LChild;
			count++;
		}
		else if(current->ID < key){
			current = current->RChild;
			count++;
		}
		else{
			count++;
			return count;
		}
		
		if(current == NULL){
			cout<<"This ID does not exist."<<endl;
			return 0;
		}
	}
}

void BinarySearchTree::deleteTree(TreeNode *current)
{
    if (current == NULL) return;
    deleteTree(current->LChild);
    deleteTree(current->RChild);
    delete current;
}

void BinarySearchTree::write_out(TreeNode *current){
	if(current){
		if(times == 0){
			ofstream coutfile;
    		coutfile.open("outputdata1.txt",ios::app);
    		for(int m = 0;m < make_up_zero(current->ID);m++){ coutfile<<0;}
    		coutfile<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
    		coutfile.close();
		}else if(times == 1){
			ofstream coutfile;
    		coutfile.open("outputdata2.txt",ios::app);
    		for(int m = 0;m < make_up_zero(current->ID);m++){ coutfile<<0;}
    		coutfile<<current->ID<<" "<<current->gender<<" "<<current->phone<<endl;
    		coutfile.close();
		}
		write_out(current->LChild);
		write_out(current->RChild);
	}
}

int BinarySearchTree::make_up_zero(long long int key){
	if(key<10){ return 5;}
	else if(key<100){ return 4;}
	else if(key<1000){ return 3;}
	else if(key<10000){ return 2;}
	else if(key<100000){ return 1;}
	else{ return 0;}
}
