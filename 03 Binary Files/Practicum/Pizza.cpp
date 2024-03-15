#include <iostream>
#include <fstream>


namespace PizzaConstants {
	constexpr int MAX_CLIENT = 50;
	constexpr int MAX_NUMBER = 20;
	constexpr int MAX_ADDRESS = 100;
	constexpr int MAX_PIZZAS = 10;
	constexpr int MAX_ORDERS = 10;
	constexpr int MAX_PIZZATYPE = 15;
	constexpr char FILENAME[] = "pizzaBinary.dat";
}

using namespace PizzaConstants;

enum Size {
	S,
	M,
	L
};

enum PizzaType {
	Margharita,
	Formagi,
	Calzone
};

struct Pizza {
	PizzaType type;
	Size size;
	double pizzaPrice;
};

struct Order {
	char clientName[MAX_CLIENT];
	int phone;
	char address[MAX_ADDRESS];
	double orderPrice;
	unsigned pizzaCount;
	Pizza pizzas[MAX_PIZZAS];

};

struct OrderList {
	Order orders[MAX_ORDERS];
	int ordersCount;
};

void writePizzaToFile(std::ofstream& ofs,const Pizza& pizza) {
	if (ofs.is_open()) {
		ofs.write((const char*)&pizza, sizeof(Pizza));
	}
}

void writePizzaToFile(const char* fileName,const Pizza& pizza) {
	std::ofstream ofs(fileName, std::ios::binary);
	writePizzaToFile(ofs, pizza);
	ofs.close();
}

void writeOrderToFile(std::ofstream& ofs, const Order& order) {
	if (!ofs.is_open()) {
		return;
	}
	ofs.write((const char*)&order.address, sizeof(order.address));
	ofs.write((const char*)&order.clientName, sizeof(order.clientName));
	ofs.write((const char*)&order.orderPrice, sizeof(order.orderPrice));
	ofs.write((const char*)&order.phone, sizeof(order.phone));
	ofs.write((const char*)&order.pizzaCount, sizeof(order.pizzaCount));
	for (int i = 0;i < order.pizzaCount;i++) {
		writePizzaToFile(ofs, order.pizzas[i]);
	}
}


Order readOrder(const char* fileName) {
	std::ifstream ifs(fileName);
	Order order = readOrder(ifs);
	ifs.close();
	return order;
}

Pizza readPizza(std::ifstream& ifs) {
	Pizza pizza;
	if (!ifs.is_open()) {
		ifs.read((char*)&pizza, sizeof(Pizza));
	}
	return pizza;
}

Pizza readPizza(const char* fileName) {
	std::ifstream ifs(fileName, std::ios::binary);
	Pizza pizza = readPizza(ifs);
	ifs.close();
	return pizza;
}

void writeOrderToFile(const char* fileName, const Order& order) {
	std::ofstream ofs(fileName, std::ios::binary);
	writeOrderToFile(ofs, order);
	ofs.close();
}

Order readOrder(std::ifstream& ifs) {
	Order order;
	if (!ifs.is_open()) {
		return{};
	}
	ifs.read((char*)&order.address, sizeof(order.address));
	ifs.read((char*)&order.clientName, sizeof(order.clientName));
	ifs.read((char*)&order.orderPrice, sizeof(order.orderPrice));
	ifs.read((char*)&order.phone, sizeof(order.phone));
	ifs.read((char*)&order.pizzaCount, sizeof(order.pizzaCount));
	for (int i = 0;i < order.pizzaCount;i++) {
		order.pizzas[i] = readPizza(ifs);
	}
	return order;
}

void writeOrderListToFile(std::ofstream& ofs, const OrderList& list) {
	if (!ofs.is_open()) {
		return;
	}
	ofs.write((const char*)&list.ordersCount, sizeof(list.ordersCount));
	for (int i = 0;i < list.ordersCount;i++) {
		writeOrderToFile(ofs, list.orders[i]);
	}
}

void writeOrderListToFile(const char* fileName, const OrderList& list) {
	std::ofstream ofs(fileName,std::ios::binary);
	writeOrderListToFile(ofs, list);
	ofs.close();
}

OrderList readOrderList(std::ifstream& ifs) {
	if (!ifs.is_open()) {
		return{};
	}
	OrderList list;
	ifs.read((char*)&list.ordersCount, sizeof(list.ordersCount));
	for (int i = 0;i, list.ordersCount;i++) {
		list.orders[i] = readOrder(ifs);
	}
	return list;
}

OrderList readOrderList(const char* fileName) {
	std::ifstream ifs(fileName,std::ios::binary);
	OrderList list=readOrderList(ifs);
	ifs.close();
	return list;
}
