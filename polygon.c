#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 100

struct point{
	int x, y;
};
struct polygon{
	int size_polygon;
	struct point   polygon_[MAX_V];
};

void NewPolygon(struct polygon *p, int n){
	int i;
	p->size_polygon = n;
	for(i = 0; i < p->size_polygon; i++){
		printf("Coordinates of %d vertice\nEnter x: ", i+1);
		scanf("%d", &p->polygon_[i].x);
		printf("Enter y: ");
		scanf("%d", &p->polygon_[i].y);
		printf("\n");
	}
	for(i = 0; i<p->size_polygon; i++){
		printf("(%d; %d)\n", p->polygon_[i].x, p->polygon_[i].y);
	}
}

void IsConvex(struct polygon *p){
	int i;
	int product[p->size_polygon];
	struct point ab, bc;
	int flag = 1;
	for(i = 0; i < p->size_polygon; i++){
		if(i==0){
			ab.x = p->polygon_[i].x - p->polygon_[p->size_polygon - 1].x;
			ab.y = p->polygon_[i].y - p->polygon_[p->size_polygon - 1].y;

			bc.x = p->polygon_[i+1].x - p->polygon_[i].x;
			bc.y = p->polygon_[i+1].y - p->polygon_[i].y;
			product[i] = ab.x * bc.y - ab.y * bc.x;
		}
		else if(i==p->size_polygon - 1){
			ab.x = p->polygon_[i].x - p->polygon_[i-1].x;
			ab.y = p->polygon_[i].y - p->polygon_[i-1].y;

			bc.x = p->polygon_[0].x - p->polygon_[i].x;
			bc.y = p->polygon_[0].y - p->polygon_[i].y;
			product[i] = ab.x * bc.y - ab.y * bc.x;
		}
		else{
			ab.x = p->polygon_[i].x - p->polygon_[i-1].x;
			ab.y = p->polygon_[i].y - p->polygon_[i-1].y;

			bc.x = p->polygon_[i+1].x - p->polygon_[i].x;
			bc.y = p->polygon_[i+1].y - p->polygon_[i].y;
			product[i] = ab.x * bc.y - ab.y * bc.x;
		}
		printf("%d\t", product[i]);
	}
	printf("\n");

	for(i = 0; i < p->size_polygon; i++){
		if(!(product[i] > 0 && product[i+1] > 0 || product[i] < 0 && product[i+1] < 0 || product[i] == 0 || product[i+1] == 0)){
			flag = 0;
			break;
		}
	}
	if(flag == 1){printf("Polygon is convex\n");}
	else if(flag == 0){printf("Polygon isn't convex\n");}
}

int main(){

	int n;
	struct polygon P;
	printf("Input number of vertices (under %d): ", MAX_V);
	scanf("%d", &n);
	if(n < MAX_V){NewPolygon(&P, n);}
	else{
		printf("! Incorrect value\n");
		return 0;
	}
	clock_t f_start = clock();
	IsConvex(&P);
	clock_t f_end = clock();
	double f_time = (double) (f_end - f_start)/CLOCKS_PER_SEC;
	printf("function time: %f\n", f_time);
}
