#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;


struct Tool
{
  char name[30];
  int quantity;
  double cost;
};

void initializeFile()
{
  ofstream file("hardware.dat", ios::binary);
  if (!file)
  {
    cout << "Failed to create the file." << endl;
    return;
  }

  Tool emptyTool;
  for (int i = 0; i < 100; i++)
  {
    file.write(reinterpret_cast<const char *>(&emptyTool), sizeof(Tool));
  }

  file.close();
}

void displayInventory()
{
  ifstream file("hardware.dat", ios::binary);
  if (!file)
  {
    cout << "Failed to open the file." << endl;
    return;
  }

  cout << setw(5) << "ID" << setw(30) << "Tool Name" << setw(10) << "Quantity" << setw(10) << "Cost" << endl;

  Tool tool;
  for (int i = 0; i < 100; i++)
  {
    file.read(reinterpret_cast<char *>(&tool), sizeof(Tool));

    if (tool.quantity > 0)
    {
      cout << setw(5) << (i + 1) << setw(30) << tool.name << setw(10) << tool.quantity << setw(10) << tool.cost << endl;
    }
  }

  file.close();
}

void addTool()
{
  fstream file("hardware.dat", ios::binary | ios::in | ios::out);
  if (!file)
  {
    cout << "Failed to open the file." << endl;
    return;
  }

  int recordNumber;
  cout << "Enter the record number (1-100): ";
  cin >> recordNumber;

  if (recordNumber < 1 || recordNumber > 100)
  {
    cout << "Invalid record number." << endl;
    return;
  }

  Tool tool;
  file.seekg((recordNumber - 1) * sizeof(Tool));
  file.read(reinterpret_cast<char *>(&tool), sizeof(Tool));

  if (tool.quantity > 0)
  {
    cout << "Tool with ID " << recordNumber << " already exists." << endl;
    return;
  }

  cout << "Enter the tool name: ";
  cin.ignore();
  cin.getline(tool.name, 30);

  cout << "Enter the quantity: ";
  cin >> tool.quantity;

  cout << "Enter the cost: ";
  cin >> tool.cost;

  file.seekp((recordNumber - 1) * sizeof(Tool));
  file.write(reinterpret_cast<const char *>(&tool), sizeof(Tool));

  file.close();
  cout << "Tool added successfully." << endl;
}

void deleteTool()
{
  fstream file("hardware.dat", ios::binary | ios::in | ios::out);
  if (!file)
  {
    cout << "Failed to open the file." << endl;
    return;
  }

  int recordNumber;
  cout << "Enter the record number (1-100) to delete: ";
  cin >> recordNumber;

  if (recordNumber < 1 || recordNumber > 100)
  {
    cout << "Invalid record number." << endl;
    return;
  }

  Tool emptyTool;
  file.seekp((recordNumber - 1) * sizeof(Tool));
  file.write(reinterpret_cast<const char *>(&emptyTool), sizeof(Tool));

  file.close();
  cout << "Tool deleted successfully." << endl;
}

void updateTool()
{
  fstream file("hardware.dat", ios::binary | ios::in | ios::out);
  if (!file)
  {
    cout << "Failed to open the file." << endl;
    return;
  }

  int recordNumber;
  cout << "Enter the record number (1-100) to update: ";
  cin >> recordNumber;

  if (recordNumber < 1 || recordNumber > 100)
  {
    cout << "Invalid record number." << endl;
    return;
  }

  Tool tool;
  file.seekg((recordNumber - 1) * sizeof(Tool));
  file.read(reinterpret_cast<char *>(&tool), sizeof(Tool));

  if (tool.quantity == 0)
  {
    cout << "Tool with ID " << recordNumber << " does not exist." << endl;
    return;
  }

  cout << "Tool Name: " << tool.name << endl;
  cout << "Quantity: " << tool.quantity << endl;
  cout << "Cost: " << tool.cost << endl;

  cout << "Enter the updated tool name: ";
  cin.ignore();
  cin.getline(tool.name, 30);

  cout << "Enter the updated quantity: ";
  cin >> tool.quantity;

  cout << "Enter the updated cost: ";
  cin >> tool.cost;

  file.seekp((recordNumber - 1) * sizeof(Tool));
  file.write(reinterpret_cast<const char *>(&tool), sizeof(Tool));

  file.close();
  cout << "Tool updated successfully." << endl;
}

int main()
{
  initializeFile();

  // Add the provided tool records
  fstream file("hardware.dat", ios::binary | ios::in | ios::out);
  if (!file)
  {
    cout << "Failed to open the file." << endl;
    return 1;
  }

  int recordNumbers[] = {3, 17, 24, 39, 56, 68, 77, 83};
  const char *toolNames[] = {"Electric sander", "Hammer", "Jig saw", "Lawn mower",
                             "Power saw", "Screwdriver", "Sledge hammer", "Wrench"};
  int quantities[] = {7, 76, 21, 3, 18, 106, 11, 34};
  double costs[] = {57.98, 11.99, 11.00, 79.50, 99.99, 6.99, 21.50, 7.50};

  for (int i = 0; i < 8; i++)
  {
    Tool tool;
    tool.quantity = quantities[i];
    tool.cost = costs[i];
    strcpy(tool.name, toolNames[i]);

    int recordNumber = recordNumbers[i];
    file.seekp((recordNumber - 1) * sizeof(Tool));
    file.write(reinterpret_cast<const char *>(&tool), sizeof(Tool));
  }

  file.close();

  int choice;
  while (true)
  {
    cout << "\n---- Tool Inventory Management ----" << endl;
    cout << "1. Display Inventory" << endl;
    cout << "2. Add Tool" << endl;
    cout << "3. Delete Tool" << endl;
    cout << "4. Update Tool" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      displayInventory();
      break;
    case 2:
      addTool();
      break;
    case 3:
      deleteTool();
      break;
    case 4:
      updateTool();
      break;
    case 5:
      return 0;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}
