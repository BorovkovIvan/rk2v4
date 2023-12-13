#include <iostream>
#include <vector>
#include <string>

class FoodItem {
protected:
    std::string name;
    std::string expirationDate;
public:
    FoodItem(const std::string& itemName, const std::string& expDate)
        : name(itemName), expirationDate(expDate) {}
    virtual void display() const {
        std::cout << "Name: " << name << "\nExpiration Date: " << expirationDate << std::endl;
        std::cout << "------------------------\n";
    }
    virtual void modify() {}
    virtual ~FoodItem() {}
};

class Vegetable : public FoodItem {
private:
    std::string type;
public:
    Vegetable(const std::string& itemName, const std::string& expDate, const std::string& vegType)
        : FoodItem(itemName, expDate), type(vegType) {}
    void display() const override {
        std::cout << "Type: " << type << "\n";
        FoodItem::display();
    }
    void modify() override {
        type = "Modified " + type;
    }
};

class DairyProduct : public FoodItem {
private:
    double fatContent;

public:
    DairyProduct(const std::string& itemName, const std::string& expDate, double fat)
        : FoodItem(itemName, expDate), fatContent(fat) {}

    void display() const override {
        std::cout << "Fat Content: " << fatContent << "%\n";
        FoodItem::display();
    }

    void modify() override {
        fatContent += 1.0;
    }
};

void modifyFoodItem(FoodItem* item) {
    item->modify();
    item->display();
}

int main() {
    std::vector<FoodItem*> foodItems;

    foodItems.push_back(new Vegetable("Carrot", "2023-01-01", "Root Vegetables"));
    foodItems.push_back(new DairyProduct("Milk", "2023-02-01", 2.5));
    foodItems.push_back(new Vegetable("Tomato", "2023-03-01", "Fruit Vegetables"));
    for (const auto& item : foodItems) {
        item->display();
    }

    for (const auto& item : foodItems) {
        modifyFoodItem(item);
    }

    for (auto& item : foodItems) {
        delete item;
    }

    return 0;
}