#include<stdio.h>
#define TITLE_LEN  20
#define AUTHOR_LEN 20
#define DESIGN_LEN 20 

struct catalog_item {
	int stock_number;
	double price;
	int item_type;
	union {
		struct {
			char title[TITLE_LEN + 1];
			char author[AUTHOR_LEN + 1];
			int num_pages;
		} book;

		struct {
			char design[DESIGN_LEN + 1];
		} mug;

		struct {
			char design[DESIGN_LEN + 1];
			int color;
			int size;
		} shirt;
	} item;
};
int main() {
	int n, c = 0;
	struct catalog_item x[100];
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		scanf("%d%lf%d", &x[j].stock_number, &x[j].price, &x[j].item_type);
		if (x[j].item_type == 0) {
			scanf("%s%s%d", &x[j].item.book.title, &x[j].item.book.author, &x[j].item.book.num_pages);
		}
		else if (x[j].item_type == 1) {
			scanf("%s", &x[j].item.mug.design);
		}
		else if (x[j].item_type == 2) {
			scanf("%s%d%d", &x[j].item.shirt.design, &x[j].item.shirt.color, &x[j].item.shirt.size);
		}
	}
	struct catalog_item temp;
	for (int pass = 1; pass < n; pass++) {
		for (int j = 0; j < n - pass; j++) {
			if (x[j].stock_number > x[j + 1].stock_number) {
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (x[i].item_type == 0) {
			printf("stock number:%d\nitem type:book\nprice:%.1lf\ntitle:%s\nauthor:%s\nnumber of pages:%d\n", x[i].stock_number, x[i].price, x[i].item.book.title, x[i].item.book.author, x[i].item.book.num_pages);
		}
		else if (x[i].item_type == 1) {
			printf("stock number:%d\nitem type:mug\nprice:%.1lf\ndesign:%s\n", x[i].stock_number, x[i].price, x[i].item.mug.design);
		}
		else if (x[i].item_type == 2) {
			printf("stock number:%d\nitem type:shirt\nprice:%.1lf\ndesign:%s\ncolor:%d\nsize:%d\n", x[i].stock_number, x[i].price, x[i].item.shirt.design, x[i].item.shirt.color, x[i].item.shirt.size);
		}

		if (c >= 0 && c < n - 1) {
			printf("--------------------\n");

		}
		c++;
	}
	return 0;
}