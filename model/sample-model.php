<?php
require_once PROJECT_ROOT_PATH . "/model/database.php";
class SampleModel extends Database
{
    public function list($limit)
    {
        return $this->select("SELECT * FROM samples ORDER BY created_at ASC LIMIT ?", ["i", $limit]);
    }

    public function get($since, $until)
    {
        return $this->select("SELECT created_at, data FROM samples WHERE created_at BETWEEN ? AND ? ORDER BY created_at ASC", ["ss", $since, $until]);
    }    
    
    public function set($data)
    {
        return $this->insert("INSERT INTO samples (data) VALUES (?)", ["s", $data]);
    }
}