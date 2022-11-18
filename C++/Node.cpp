#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string name;
    std::vector<Node> kids{};
    Node* parent{nullptr};
};

void init_parents(Node& tree) {
    for (auto& kid: tree.kids) {
        kid.parent = &tree;
        init_parents(kid);
    }
}

void walk(
    Node const& tree,
    std::function<void(Node const& node, int depth)> action,
    int depth = 0) {
    action(tree, depth);
    for (auto const& kid: tree.kids) {
        walk(kid, action, depth + 1);
    }
}

void print(Node const& tree) {
    walk(tree, [](auto const& node, auto depth) {
        std::cout << std::string(2 * depth, ' ') << node.name << "\n";
    });
}

int calc_total_depth(Node const& tree) {
    auto total = 0;
    walk(tree, [&total](auto const& _, auto depth) {
        total += depth;
    });
    return total;
}

Node& process(Node& intro) {
    auto tree = Node {"root", {
        intro,
        {"one", {
            {"two"},
            {"three"},
        }},
        {"four"},
    }};
    init_parents(tree);
    print(tree);
    auto total_depth = 0;
    for (auto i = 0; i < 200'000'000; ++i) {
        total_depth += calc_total_depth(tree);
    }
    std::cout << "total_depth: " << total_depth << "\n";
    return intro;
}

int main(int argc, char* argv[])
{
    auto intro = Node {"intro"};
    auto node = process(intro);
    return 0;
}


