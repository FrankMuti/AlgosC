cmake_minimum_required(VERSION 3.23)
project(AlgosC CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgosC main.cpp

        templates/data_structures/Mint.hpp templates/data_structures/SegmentTree.hpp templates/data_structures/LazySegmentTree.hpp
        templates/data_structures/RMQ.hpp templates/polynomials/Polynomial.hpp templates/polynomials/PolyRoots.hpp
        templates/polynomials/PolyInterpolate.hpp templates/numerical/Simplex.hpp templates/data_structures/FenwickTree.hpp
        templates/number_theory/CRT.hpp templates/graphs/BellmanFord.hpp templates/graph/Point.hpp templates/graph/LineDistance.hpp
        templates/graph/SegmentDistance.hpp templates/graph/SegmentIntersection.hpp templates/graph/LineIntersection.hpp templates/graph/SideOf.hpp
        templates/graph/Angle.hpp templates/numerical/BigInt.hpp templates/number_theory/FastEratothesnes.hpp
        templates/number_theory/ModMulLL.hpp templates/number_theory/MillerRabin.hpp templates/number_theory/Factor.hpp)
