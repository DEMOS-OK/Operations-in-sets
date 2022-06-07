#pragma once

#include <string>
#include <set>

namespace sets {
	std::set<std::string> enterSet(const std::string setName);
	void fillSetFromString(std::set<std::string>* pointerSet, std::string inputString);
	std::string prepareToPrint(std::set<std::string>* pointerSet, const std::string nameOfSet);
	bool checkEquality(std::set<std::string>* pointerSetA, std::set<std::string>* pointerSetB);
	bool checkSubset(std::set<std::string>* pointerSetA, std::set<std::string>* pointerSetB);
	bool elementInSet(const std::string elementA, std::set<std::string>* pointerSetB);
	std::set<std::string> merge(std::set<std::string>* pointerSetA, std::set<std::string>* pointerSetB);
	std::set<std::string> intersection(std::set<std::string>* pointerSetA, std::set<std::string>* pointerSetB);
	std::set<std::string> difference(std::set<std::string>* pointerSetA, std::set<std::string>* pointerSetB);
	std::set<std::string> symmetricalDifference(std::set<std::string>* pointerSetA, std::set<std::string>* pointerSetB);
}
