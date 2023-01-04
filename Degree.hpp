//
//  degree.h
//  C867
//
//  Created by Madeline Baum on 1/2/23.
//
#pragma once
#include <string>
#ifndef degree_h
#define degree_h


enum class Degree { UNDECIDED, SECURITY, NETWORK, SOFTWARE };
static const std::string degreeStrings[] = { "UNDECIDED", "SECURITY", "NETWORK", "SOFTWARE"};
#endif /* degree_h */
