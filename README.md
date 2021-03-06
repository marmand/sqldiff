SQLDiff
=======

The project SQLDiff is part of an idea of mine, that is to allow to store
a database schema in git.
As git is a really great DCVS, I plan to respect it's features.

Mainly, git is made to handle version information and source evolutions.
As such, it is commonly used by developpers (as me) to handle their sources.
Some developers needs to have a database to store their project data, and as
such, they need to store somewhere their database schema, and their migrations.

Most, according to what I've found so far on
* Liquibase
* Flyway
store all their migrations in the same place as their sources.
That is understandable, but not in accordance with how git works.

Usage:
------

```lang=SQL, name=v0.sql
CREATE TABLE toto (ID INT);
```

```lang=SQL, name=v1.sql
CREATE TABLE toto (ID INT, value BIGINT);
```

```lang=sh
./sqldiff v0.sql v1.sql
ALTER TABLE toto
ADD value BIGINT
;
```

Contribute
----------

If you ever want to contribute to this project, you can join me on http://phabricator.leclercq.site where
you'll gain access to my projects issue tracker/repository.
