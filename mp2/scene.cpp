#include "scene.h"
#include "image.h"
#include <iostream>
using namespace std;
/* 1.how to initialize a array on stack/heap int x[6]. x is the name of the array; int* arrayPtr; arrayPtr = new int[6]; delete[]
   2.
*/


Scene::Scene(int max){//mouwentei
	maxLayers = max;
	imageArray = new Image*[max];
	xcoords = new unsigned long[max];
	ycoords = new unsigned long[max];
	for(int i = 0; i < max;i++){
		imageArray[i] = NULL;
		xcoords[i] = 0;
		ycoords[i] = 0;
	}
	cout<<"consOK"<<endl;
}

Scene::~Scene(){//mouwentei
	for(int i = 0;i<maxLayers;i++){
		if(imageArray[i]!=NULL){
			delete imageArray[i];
			imageArray[i] = NULL;
		}
	}
	delete imageArray;
	delete xcoords;
	delete ycoords;
	imageArray = NULL;
	xcoords = NULL;
	ycoords = NULL;
	cout<<"desOK"<<endl;
	}
	
Scene::Scene(const Scene & source){//mouwentei
	copy(source);
}

const Scene &Scene::operator=(const Scene & source){
	if(this!= &source){//check against self assignment
		clear();
		copy(source);
	}
	cout<<"opraOK"<<endl;
	return *this;
}	
		
void Scene::changemaxlayers(int newmax){
	Image** temp = new Image*[newmax];
	int nonNull = 0;
	for(int i = 0; i<maxLayers;i++){
		if(imageArray[i]!=NULL)
		nonNull++;
	}
	cout<<"reached line 55"<<endl;
	if(nonNull>maxLayers){
		cout << "invalid newmax" << endl;
		delete[] temp;
		return;
	}else{
		for(int i = 0; i<maxLayers;i++){
				if(imageArray[i]!=NULL&&i<newmax){
					temp[i] = imageArray[i];
				}else if(imageArray[i]!=NULL&&i>newmax){
					cout << "invalid newmax" << endl;
					return;
				}
			}
		}
		delete imageArray;
		imageArray = temp;
		temp = NULL;
		maxLayers = newmax;
		cout<<"changemaxlayerOK"<<endl;
}
		
					
	
void Scene::addpicture(const char* FileName, int index,int x,int y){
	if(index>maxLayers||index<0){
		cout << "index out of bounds" << endl;
		return;
	}
	Image* imageIn = new Image;
	imageIn->readFromFile(FileName);
	imageArray[index] = imageIn;
	xcoords[index] = x;
	ycoords[index] = y;
	cout<<"addPicOK"<<endl;
}

void Scene::changelayer(int index, int newindex){
	if(index == newindex){
		return;
	}
	if(index<0||index>maxLayers||newindex<0||newindex>maxLayers){
		cout << "invalid index" << endl;
	}
	if(imageArray[newindex]!=NULL){
		delete[] imageArray[newindex];
		imageArray[newindex] = NULL;
		imageArray[newindex] = imageArray[index];
		imageArray[index] = NULL;
	}else{
		imageArray[newindex] = imageArray[index];
		xcoords[newindex] = xcoords[index];
		ycoords[newindex] = ycoords[index];
		imageArray[index] = NULL;
	}
}

void Scene::translate(int index, int xcoord, int ycoord){
	if(imageArray[index]==NULL||index>maxLayers||index<0){
		cout << "invalid index" << endl;
		return;
	}
	xcoords[index] = xcoord;
	ycoords[index] = ycoord;
}

void Scene::deletepicture(int index){
if(imageArray[index]==NULL||index>maxLayers||index<0){
		cout << "invalid index" << endl;
		return;
	}
	delete imageArray[index];
	imageArray[index] = NULL;
	xcoords[index] = 0;
	ycoords[index] = 0;
}

Image* Scene::getpicture(int index)const{
	if(imageArray[index]==NULL||index<0||index>maxLayers-1){
		cout << "invalid index" << endl;
		return NULL;
	}
	return imageArray[index];
}

Image Scene::drawscene() const{
	unsigned long height = 0;
	unsigned long width = 0;
	cout<<"widthHeightIni"<<endl;
	for(int i = 0;i<maxLayers;i++){//go through the whole array and compare the i th member in all 3 arrays
		if(imageArray[i]!=NULL){
			if(imageArray[i]->width()+xcoords[i]>width){//if the 
				 width = imageArray[i]->width()+xcoords[i];
			}
			if(imageArray[i]->height()+ycoords[i]>height){
				 height = imageArray[i]->height()+ycoords[i];
			}
		}
	}
	cout<<"widthHeightOK"<<endl;
	Image output = Image();
	output.resize(width,height);
	cout<<"resizeOK"<<endl;
	for(int a = 0;a<maxLayers;a++){
		if(imageArray[a]!=NULL){
			cout<<"reached line 143"<<endl;
			for(unsigned long k = xcoords[a];k<xcoords[a]+imageArray[a]->width();k++){
				for(unsigned long j = ycoords[a];j<ycoords[a]+imageArray[a]->height();j++){
					*(output(k,j)) = *((*(imageArray[a]))((k-xcoords[a]),(j-ycoords[a])));
				}
			}
		}
	}
		cout<<"drawsceneOK"<<endl;
		return output;
}

void Scene::copy(const Scene & other){
	maxLayers = other.maxLayers;
	imageArray = new Image*[other.maxLayers];
	xcoords = new unsigned long[maxLayers];
	ycoords = new unsigned long[maxLayers];
	for(int i = 0;i<maxLayers;i++){
		imageArray[i] = other.imageArray[i];
		xcoords[i] = other.xcoords[i];
		ycoords[i] = other.ycoords[i];
		if(other.imageArray[i]!=NULL){
			imageArray[i] = new Image(*(other.imageArray[i]));
		}
		else{
		imageArray[i] = NULL;
		}
	}
}
		
void Scene::clear(){
	for(int i = 0;i<maxLayers;i++){
		if(imageArray[i]!=NULL){//yaobuyao
		delete imageArray[i];
		imageArray[i] = NULL;
		}
	}
	delete[] imageArray;
	delete[] xcoords;
	delete[] ycoords;
	imageArray = NULL;
	xcoords = NULL;
	ycoords = NULL;
}

int Scene::getLayers(){
	return this->maxLayers;
}

	
	
