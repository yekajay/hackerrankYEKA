bool has_cycle(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while ((fast != nullptr) && (slow != nullptr)) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}
