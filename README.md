# Purchase Order Processor - C++ Project

**Name:** Joshua Lavieri  
**Course:** Foundations of Computer Science  

---

## 📘 Overview
This project was created as part of a college assignment. It is written in C++ and demonstrates working with file input/output, data processing, and structured program design with functions.  

The program processes purchase orders from a file, using a **phone number** and an **item number** to verify the product and calculate costs.  

---

## ⚙️ Program Workflow
The program reads data from an input file (`purchase_data.txt`) and performs the following steps:

1. **Input Function**  
   - Reads customer phone number, item number, quantity, price, and processing plant number.

2. **Process Function**  
   - Determines the tax rate based on the processing plant number.  
   - Calculates the order tax, net cost, and total cost.

3. **Output Function**  
   - Displays the results neatly formatted in columns.

---

## 🛠️ How to Compile and Run
Make sure you have a C++ compiler installed (like `g++`).  

```bash
# Compile
g++ purchase_order.cpp -o purchase_order

# Run
./purchase_order
```

The program expects a file named `purchase_data.txt` in the same directory as the executable.  

**Example file format (`purchase_data.txt`):**
```
5551234567 A123 10 29.99 42
5559876543 B456 5 15.50 120
```

---

## ✨ Features
- Reads input from a text file.  
- Calculates order costs (net, tax, total) automatically.  
- Uses modular functions (`input`, `process`, `output`) for clarity.  
- Demonstrates conditional logic with tax rate ranges.  

---

## 📚 Notes
- This was created as a **college project** for practice with C++ file I/O and functions.  
- Not intended for real-world order processing.  

