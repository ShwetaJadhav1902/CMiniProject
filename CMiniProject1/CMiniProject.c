#include<stdio.h>
#include<string.h> 

struct Movie
{
	char movieName[10];
	int duration;
	char category[10];
	int ticketCost;
};

int CalculateTicketCost(struct Movie* m, char circle[]) {

	if (!strcmp(m->category, "2D") && !strcmp(circle, "gold")) {
		m->ticketCost = 300;
		return 0;
	}
	else if (!strcmp(m->category, "3D") && !strcmp(circle, "gold")) {
		m->ticketCost = 500;
		return 0;
	}
	else if (!strcmp(m->category, "2D") && !strcmp(circle, "silver")) {
		m->ticketCost = 250;
		return 0;
	}
	else if (!strcmp(m->category, "3D") && !strcmp(circle, "silver")) {
		m->ticketCost = 450;
		return 0;
	}
	else if ((strcmp(m->category, "2D") && (strcmp(m->category, "3D"))) && (strcmp(circle, "gold") && strcmp(circle, "silver")))
		return 3;
	else if (strcmp(m->category, "2D") && (strcmp(m->category, "3D")))
		return 1;
	else if (strcmp(circle, "gold") && strcmp(circle, "silver"))
		return 2;
}

char* GetCircleDetails(char* circle, int size) {
	printf("Enter Circle: \n");
	return gets(circle, size, stdin);
}

void GetMovieDetails(struct Movie* m) {
	printf("Enter Movie Name: \n");
	gets(m->movieName);
	printf("Enter Movie Category: \n");
	gets(m->category);
	printf("Enter Movie Duration: \n");
	scanf_s("%d", &m->duration);
	m->ticketCost = 0;
}


int main() {
	int z = 9;
	char circle[10];
	struct Movie m;

	GetCircleDetails(circle, sizeof(circle));

	GetMovieDetails(&m);

	z = CalculateTicketCost(&m, circle);


	if (z == 0)
		printf("The ticket cost is: %d", m.ticketCost);
	else if (z == 1)
		printf("Sorry, there is no %s type of Category in the theater!\n", m.category);
	else if (z == 2)
		printf("Sorry, Invalid circle!\n");
	else if (z == 3)
		printf("Sorry, both Category and Circle are Invalid!\n");

	return 0;
}