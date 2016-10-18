#pragma once
#include <cstring> 
#include "article_info.hpp"

#include "../env/assert.hpp"

#include "../std/vector.hpp"
#include "../std/noncopyable.hpp"
#include "../std/map.hpp"


class Storage : noncopyable
{
  string const & GetUrl(size_t ind) const { return m_info[ind].m_url; }
  bool IsRedirect(size_t ind) const { return m_info[ind].m_redirect; }

  class ResultsAccumulator
  {
    Storage const & m_storage;

    typedef map<string, size_t> MapT;
    MapT m_map;

  public:
    ResultsAccumulator(Storage & storage) : m_storage(storage) {}

    void Add(size_t ind);
    bool IsExist(size_t ind) const;

    void GetResults(vector<size_t> & out, double lat, double lon) const;
  };

public:
  void Load(rd::Reader & reader);
  void Load(string const & path);

  void QueryArticleInfo(string const & prefix,
                        double lat = EMPTY_COORD, double lon = EMPTY_COORD);

  /// @name For unit tests only.
  //@{
  ArticleInfo const & GetArticle(size_t i) const { return m_info[i]; }
  ArticleInfo const * GetParentForIndex(size_t i) const
  {
    ASSERT(i < m_info.size(), ());
    return (m_info[i].m_parentIndex != ArticleInfo::NO_PARENT ? &m_info[m_info[i].m_parentIndex] : 0);
  }
  //@}

  /// @name Results processing.
  //@{
  size_t GetResultsCount() const { return m_lastQuery.size(); }

  ArticleInfo const & GetResult(size_t i) const
  {
    ASSERT(i < m_lastQuery.size(), ());
    return m_info[m_lastQuery[i]];
  }

  /// Format parent's name like: father > grand father > ...
  string FormatParentName(ArticleInfo const & info, int maxDepth = 2) const;

  /// Find article by url.
  ArticleInfo const * GetArticleInfoFromUrl(string const & url) const;
  //@}

protected:
  friend class StorageBuilder;

  vector<ArticleInfo> m_info;
  vector<size_t> m_lastQuery;

  string const & GetKey(size_t i) const
  {
    return m_info[i].m_key;
  }

  class LessScore
  {
    Storage const & m_storage;
    double m_lat, m_lon;

    ArticleInfo const & Get(size_t i) const
    {
      return m_storage.m_info[i];
    }

  public:
    LessScore(Storage const & storage, double lat, double lon)
      : m_storage(storage), m_lat(lat), m_lon(lon)
    {
    }

    bool operator() (size_t i1, size_t i2) const;
  };
};
