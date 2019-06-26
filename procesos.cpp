#include <iostream>
#include<thread>
//#include<array>
#include<vector>

using namespace std;

unsigned int gpc;


class Proceso {
	private:
		unsigned int id;
		unsigned int ex_time;
		
	public:
		Proceso (int t = 1){
			this->id = ++gpc;
			this->ex_time = t;
		}
		
		Proceso (int id, int t){
			this->id = id;
			this->ex_time = t;
		}
		
		int cambiar_ex_time (int t){
			if(t>=1){
				this->ex_time=t;
			}else{
				this->ex_time=t;
			}
			return this->ex_time;
		}
		
		void avanzar (){
			this->ex_time--;
		}
		
		void esperar (){
			for(int i=0;i<ex_time;i++){
				this->avanzar();
			}
		}
};

unsigned int core_number = thread::hardware_concurrency();
vector<Proceso> ready_q;
vector<Proceso> wait_q;

void cambiar_core_count (int c){
	if(c<1){
		cout<<"error\n";
	}else{
		core_number = c;
	}
}

bool ingresar_proceso (Proceso p){
	if(ready_q.size() < core_number){
		ready_q.push_back(p);
		return true;
	}else{
		return false;
	}	
}

bool sacar_proceso (int index){
	if (ready_q.empty()){
		return false;
	}else{
		ready_q.erase(ready_q.begin()+index);
		ready_q.shrink_to_fit();
		return true;
	}
}

void mover_proceso(){
	if(!wait_q.empty()){
		Proceso p = wait_q[0];
		wait_q.erase(wait_q.begin());
		ingresar_proceso(p);
	}
}
