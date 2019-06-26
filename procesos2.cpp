#include <iostream>
#include<thread>
//#include<array>
#include<vector>
#include<cstring>

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
		
		int get_id(){return id;}
		int get_ex_time(){return ex_time;}
		
		void mod_id(int i){this->id = i;}
		
		void borrar(){this->id = 0;}
		
		int cambiar_ex_time (int t){
			if(t>=1){
				this->ex_time=t;
			}else{
				this->ex_time=t;
			}
			return this->ex_time;
		}
		
		int avanzar (){
			this->ex_time--;
			return this->ex_time;
		}
		
		void esperar (){
			for(int i=0;i<ex_time;i++){
				this->avanzar();
			}
		}
		
		
};

unsigned int core_number = thread::hardware_concurrency();

Proceso null_p (0);
vector<Proceso> ready_q (8);
vector<Proceso> wait_q;

bool rq_empty (){
	for(int i=0;i<ready_q.size();i++){
		if(ready_q[i].get_id() != 0)
			return false;
		return true;
	}
}

void inicializar_rq (int c=core_number){
	for(int i=0;i<c;i++){
		ready_q[i].borrar();
	}
}

void cambiar_core_count (int c){
	if(c<1){
		cout<<"error\n";
	}else{
		core_number = c;
	}
}

int get_rq_space (){
	for(int i=0;i<ready_q.size();i++){
		if(ready_q[i].get_id() == 0){
			return i;
		}
	}
	return -1;
}

void push_p_rq (Proceso p){
	int index = get_rq_space();
	if(index != -1){
		ready_q[index] = p;
		return;
	}
}

void ingresar_p (int t=3){
	Proceso p(t);
	wait_q.push_back(p);
}

bool sacar_proceso (int index){
	if (rq_empty()){
		return false;
	}else{
		ready_q[index].borrar();
		return true;
	}
}

void mover_procesos(){
	int i;
	while(!wait_q.empty()){
		i = get_rq_space();
		if(i==-1)
			break;
		ready_q[i] = wait_q[0];
		wait_q.erase(wait_q.begin());
	}
}

void av_procesos(){
	for(int i=0;i<ready_q.size();i++){
		if(ready_q[i].avanzar() <= 0){
			cout<<endl<<">>El Proceso "<<ready_q[i].get_id()<<" ha salido <<"<<endl;
			if(!sacar_proceso(i)){cout<<"error\n";}
		}
	}
}

void imprimir_rq (){
	for(int i=0;i<ready_q.size();i++){
		cout<<"Procesador "<<i;
		if(ready_q[i].get_id() != 0){
			cout<<" | ID :"<<ready_q[i].get_id()<<" | Tiempo Ejecucion: "<<ready_q[i].get_ex_time()<<endl;
		}else{
			cout<<" No tiene procesos asociados\n";
		}
	}
}

int get_p_count (){
	int count = 0;
	for(int i=0;i<ready_q.size();i++){
		if(ready_q[i].get_id() !=  0)
			count++;
	}
	return count;
}
