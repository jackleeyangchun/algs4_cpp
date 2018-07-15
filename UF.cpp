/*
	class Sales_item{
		public:
			double avg_price()const;
			bool same_isbn(const Sales_item &rhs) const
			{
				return isbn == rhs.isbn;
			}

		private:
			std::string isbn;
			unsigned units_sold;
			double revenue;
	};
*/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>

#define DEBUG 0

using namespace std;

class UF
{
	public:
		UF(int N);
		void Union(int p, int q);
		int Find(int p);
		bool Connected(int p, int q);
		int Count();
		~UF();

	private:
		int *id;
		int count;
		int length;
};

UF::UF(int N)
{
	length = count = N;
	id = new int[N];
	for(int i=0; i<N; i++)
		id[i] = i;
}
UF::~UF()
{
	if(id != NULL)
		delete(id);
}

int UF::Count()
{
	return count;
}

bool UF::Connected(int p, int q)
{
	return Find(p) == Find(q);
}

int UF::Find(int p)
{
	return id[p];
}

void UF::Union(int p, int q)
{
	int pID = Find(p);
	int qID = Find(q);

	if(pID == qID)
		return;

	for(int i=0; i<length; i++){
		if(id[i] == pID)
			id[i] = qID;
	}

	count -- ;
}


int main(int argc, char*argv[])
{
	cout << __FILE__ << ": Initial Finish." << endl;
	ifstream src_file;
	int N = 0;	
	int p = 0;
	int q = 0;

	src_file.open("tinyUF.txt", ios_base::in);
	src_file >> N;
	UF uf(N);

	while(src_file >> p >> q)	// read file is not empty
	{

		if(uf.Connected(p,q))
			continue;

		uf.Union(p,q);
		cout << p <<" " << q << " " << endl;
	}

		cout << uf.Count() << " Components." << endl;

	src_file.close();
	src_file.clear();
	cout << "Done !!! " << endl; 
}

/*
	end of file
*/
