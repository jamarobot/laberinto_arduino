#include <Maze.h>


void Maze::test(int maze[MAZE_HEIGHT][MAZE_WIDTH],int x_,int y_,int goalX, int goalY){
	Serial.println("entro aqui");
	for(int i=0;i<MAZE_HEIGHT;i++){
		for(int k=0;k<MAZE_WIDTH;k++){
			this->maze[i][k]=(maze[i][k]);
		}
		
	}
	found=false;

	for(int i=0;i<MAZE_HEIGHT;i++){
		for(int k=0;k<MAZE_WIDTH;k++){
			Serial.print(this->maze[i][k]);
		}
		Serial.println();
	}
    //this->*maze=&*maze;
    this->initX=x_;
    this->initY=y_;
	this->goalX=goalX;
	this->goalY=goalY;
	setup();
	
    pinMode(9,OUTPUT);
    digitalWrite(9,HIGH);
 
   
printState();
	while (!found)
	{
		expand();
	//	printState();
	//	printParent();
	}
	printParent();
	//List<int*> coords;
	int y=goalY,x=goalX;
	int diffY,diffX;
	String path;
	do{
		Serial.print(y);
		Serial.print("-");
		Serial.println(x);

		Serial.print(parent[y][x][0]);
		Serial.print("-");
		Serial.println(parent[y][x][1]);
	
		diffY=(y-parent[y][x][0]);
		diffX=(x-parent[y][x][1]);
		if(diffY==0){
			path=((diffX==-1)?"A":"D")+path;
		}else if(diffX==0){
			path=((diffY==-1)?"W":"S")+path;
		}else{
			Serial.println("no deberia entrar aqui");
			Serial.println(diffX);
			Serial.println(diffY);
		}

		Serial.print(diffY);
		Serial.print("-");
		Serial.println(diffX);
		//int cord[2]={parent[y][x][0],parent[y][x][1]};
	
		//coords.Add(cord);
		int aux=y;
		y=parent[y][x][0];
		x=parent[aux][x][1];
		
	}while(y!=initY  || x!=initX );
	
	Serial.print(path);
  //  expand();
	
}

void Maze::expand(){
   
   for(int i=0;i<MAZE_HEIGHT;i++){
		for(int k=0;k<MAZE_WIDTH;k++){
			if(state[i][k]==EDGE || state[i][k]==INIT){
				if(bitRead(this->maze[i][k],UP)==0 && !found){//no hay pared			
					registrar(i-1,k,i,k);					
				}
				if(bitRead(this->maze[i][k],RIGHT)==0 && !found){//no hay pared			
					registrar(i,k+1,i,k);					
				}
				if(bitRead(this->maze[i][k],DOWN)==0 && !found){//no hay pared			
					registrar(i+1,k,i,k);					
				}
				if(bitRead(this->maze[i][k],LEFT)==0 && !found){//no hay pared			
					registrar(i,k-1,i,k);					
				}
				state[i][k]=SEARCHED;
			}
		}
	}
   
};
void Maze::registrar(int i, int k,int py,int px){
	if(state[i][k]==FREE){						
		state[i][k]=EDGE;
		parent[i][k][0]=py;
	parent[i][k][1]=px;
	}else if(state[i][k]==GOAL){
		found=true;
		Serial.println("encontrado");
		parent[i][k][0]=py;
	parent[i][k][1]=px;
	}
	
}
void Maze::setup(){
	for(int i=0;i<MAZE_HEIGHT;i++){
		for(int k=0;k<MAZE_WIDTH;k++){
			state[i][k]=0;
		}
	}
	state[initY][initX]=INIT;
	state[goalY][goalX]=GOAL;

	
}
void Maze::printState(){
	for(int i=0;i<MAZE_HEIGHT;i++){
		for(int k=0;k<MAZE_WIDTH;k++){
			Serial.print(state[i][k]);
		}
		Serial.println();
	}
}
void Maze::printParent(){
	for(int i=0;i<MAZE_HEIGHT;i++){
		for(int k=0;k<MAZE_WIDTH;k++){
			Serial.print(parent[i][k][0]);
			Serial.print("-");
			Serial.print(parent[i][k][1]);
			Serial.print("|");
		}
		Serial.println();
	}
}