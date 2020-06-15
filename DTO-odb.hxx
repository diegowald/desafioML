// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef DTO_ODB_HXX
#define DTO_ODB_HXX

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <odb/boost/date-time/pgsql/gregorian-traits.hxx>
#include <odb/boost/date-time/pgsql/posix-time-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "DTO.h"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>
#include <odb/view-image.hxx>
#include <odb/view-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // DNA
  //
  template <>
  struct class_traits< ::DNA >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::DNA >
  {
    public:
    typedef ::DNA object_type;
    typedef ::DNA* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef long unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };

  // Statistics
  //
  template <>
  struct class_traits< ::Statistics >
  {
    static const class_kind kind = class_view;
  };

  template <>
  class access::view_traits< ::Statistics >
  {
    public:
    typedef ::Statistics view_type;
    typedef ::Statistics* pointer_type;

    static void
    callback (database&, view_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // DNA
  //
  template <typename A>
  struct query_columns< ::DNA, id_pgsql, A >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        long unsigned int,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // chain
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    chain_type_;

    static const chain_type_ chain;

    // isMutant
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        bool,
        pgsql::id_boolean >::query_type,
      pgsql::id_boolean >
    isMutant_type_;

    static const isMutant_type_ isMutant;
  };

  template <typename A>
  const typename query_columns< ::DNA, id_pgsql, A >::id_type_
  query_columns< ::DNA, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::DNA, id_pgsql, A >::chain_type_
  query_columns< ::DNA, id_pgsql, A >::
  chain (A::table_name, "\"chain\"", 0);

  template <typename A>
  const typename query_columns< ::DNA, id_pgsql, A >::isMutant_type_
  query_columns< ::DNA, id_pgsql, A >::
  isMutant (A::table_name, "\"isMutant\"", 0);

  template <typename A>
  struct pointer_query_columns< ::DNA, id_pgsql, A >:
    query_columns< ::DNA, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::DNA, id_pgsql >:
    public access::object_traits< ::DNA >
  {
    public:
    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // _id
      //
      long long _id_value;
      bool _id_null;

      // _chain
      //
      details::buffer _chain_value;
      std::size_t _chain_size;
      bool _chain_null;

      // _isMutant
      //
      bool _isMutant_value;
      bool _isMutant_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 3UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::DNA, id_common >:
    public access::object_traits_impl< ::DNA, id_pgsql >
  {
  };

  // Statistics
  //
  template <>
  class access::view_traits_impl< ::Statistics, id_pgsql >:
    public access::view_traits< ::Statistics >
  {
    public:
    struct image_type
    {
      // isMutant
      //
      bool isMutant_value;
      bool isMutant_null;

      // quantity
      //
      int quantity_value;
      bool quantity_null;

      std::size_t version;
    };

    typedef pgsql::view_statements<view_type> statements_type;

    typedef pgsql::query_base query_base_type;
    struct query_columns
    {
    };

    static const bool versioned = false;

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&);

    static void
    init (view_type&,
          const image_type&,
          database*);

    static const std::size_t column_count = 2UL;

    static query_base_type
    query_statement (const query_base_type&);

    static result<view_type>
    query (database&, const query_base_type&);

    static const char query_statement_name[];
  };

  template <>
  class access::view_traits_impl< ::Statistics, id_common >:
    public access::view_traits_impl< ::Statistics, id_pgsql >
  {
  };

  // DNA
  //
}

#include "DTO-odb.ixx"

#include <odb/post.hxx>

#endif // DTO_ODB_HXX
