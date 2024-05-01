#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Function to handle user queries and generate responses
string getResponse(const string& query) {
    // Database of product information
    map<string, string> productInfo;
    productInfo["features"] = "Our product offers advanced features like X, Y, and Z.";
    productInfo["price"] = "The price of our product starts from $X.";
    productInfo["availability"] = "Our product is currently in stock and available for purchase.";
    productInfo["contact"] = "For any further inquiries, please contact us at contact@example.com.";
    productInfo["default"] = "I'm sorry, I didn't understand your query. How can I assist you?";

    // Check if the query matches any known information
    map<string, string>::iterator it = productInfo.find(query);
    if (it != productInfo.end()) {
        return it->second;
    } else {
        // If the query doesn't match, return a default response
        return productInfo["default"];
    }
}

int main() {
    cout << "Welcome to our product support chatbot!\n";
    cout << "How can I assist you today?\n";

    string query;
    while (true) {
        cout << "You: ";
        getline(cin, query);

        // Convert the query to lowercase for easier comparison
        transform(query.begin(), query.end(), query.begin(), ::tolower);

        // Get the response based on the user query
        string response = getResponse(query);
        
        cout << "Chatbot: " << response << endl;

        // End the conversation if the user indicates they are done
        if (query == "exit" || query == "quit" || query == "bye") {
            cout << "Chatbot: Thank you for using our product support chatbot. Goodbye!\n";
            break;
        }
    }

    return 0;
}
/*
input for the code
Welcome to our product support chatbot!
How can I assist you today?
You: What are the features of your product?
Chatbot: Our product offers advanced features like X, Y, and Z.
You: What is the price?
Chatbot: The price of our product starts from $X.
You: Is the product available?
Chatbot: Our product is currently in stock and available for purchase.
You: How can I contact you?
Chatbot: For any further inquiries, please contact us at contact@example.com.
You: Thank you
Chatbot: I'm sorry, I didn't understand your query. How can I assist you?
You: Bye
Chatbot: Thank you for using our product support chatbot. Goodbye!
*/