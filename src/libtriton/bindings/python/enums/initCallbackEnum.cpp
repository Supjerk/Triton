//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#include <triton/pythonBindings.hpp>
#include <triton/callbacksEnums.hpp>



/*! \page py_CALLBACK_page CALLBACK
    \brief [**python api**] All information about the CALLBACK python namespace.

\tableofcontents

\section CALLBACK_py_description Description
<hr>

The CALLBACK namespace contains all kinds of callbacks.

\subsection CALLBACK_py_example Example

~~~~~~~~~~~~~{.py}
>>> addCallback(your_function, CALLBACK.GET_CONCRETE_MEMORY_VALUE)
~~~~~~~~~~~~~

\section CALLBACK_py_api Python API - Items of the CALLBACK namespace
<hr>

- **CALLBACK.GET_CONCRETE_MEMORY_VALUE**<br>
The callback takes as arguments a \ref py_TritonContext_page and a \ref py_MemoryAccess_page. Callbacks will be called each time that the
Triton library will need to LOAD a concrete memory value. The callback must return nothing.

- **CALLBACK.GET_CONCRETE_REGISTER_VALUE**<br>
The callback takes as arguments a \ref py_TritonContext_page and a \ref py_Register_page. Callbacks will be called each time that the
Triton library will need to GET a concrete register value. The callback must return nothing.

- **CALLBACK.SET_CONCRETE_MEMORY_VALUE**<br>
The callback takes as arguments a \ref py_TritonContext_page, a \ref py_MemoryAccess_page and an integer. Callbacks will be called
each time that the Triton library will need to STORE a concrete memory value. The callback must return nothing.

- **CALLBACK.SET_CONCRETE_REGISTER_VALUE**<br>
The callback takes as arguments a \ref py_TritonContext_page, \ref py_Register_page and an integer. Callbacks will be called each time that the
Triton library will need to PUT a concrete register value. The callback must return nothing.

- **CALLBACK.SYMBOLIC_SIMPLIFICATION**<br>
Defines a callback which be called before all symbolic assignments. The callback takes as arguments
a \ref py_TritonContext_page and an \ref py_AstNode_page. This callback must return a valid \ref py_AstNode_page. The returned node is
used as assignment. See also the page about \ref SMT_simplification_page.

*/



namespace triton {
  namespace bindings {
    namespace python {

      void initCallbackEnum(pybind11::module& pyTriton) {
        /* CALLBACK Enum */
        pybind11::enum_<triton::callbacks::callback_e>(pyTriton, "CALLBACK")
          .value("GET_CONCRETE_MEMORY_VALUE",   triton::callbacks::GET_CONCRETE_MEMORY_VALUE)
          .value("GET_CONCRETE_REGISTER_VALUE", triton::callbacks::GET_CONCRETE_REGISTER_VALUE)
          .value("SET_CONCRETE_MEMORY_VALUE",   triton::callbacks::SET_CONCRETE_MEMORY_VALUE)
          .value("SET_CONCRETE_REGISTER_VALUE", triton::callbacks::SET_CONCRETE_REGISTER_VALUE)
          .value("SYMBOLIC_SIMPLIFICATION",     triton::callbacks::SYMBOLIC_SIMPLIFICATION);
      }

    }; /* python namespace */
  }; /* bindings namespace */
}; /* triton namespace */