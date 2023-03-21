<?php
require_once PROJECT_ROOT_PATH . "/model/database.php";
class SampleModel extends Database
{
    public function list($limit)
    {
        return $this->select("SELECT * FROM samples ORDER BY created_at DESC LIMIT ?", ["i", $limit]);
    }

    public function get($since, $until)
    {
        return $this->select("SELECT created_at, data FROM samples WHERE created_at BETWEEN ? AND ? ORDER BY created_at ASC", ["ss", $since, $until]);
    }    
    
    public function set($data)
    {
        $timestamp = date('Y-m-d H:i:s');
        return $this->insert("INSERT INTO samples (created_at, data) VALUES (?,?)", ["ss", $timestamp, $data]);
    }
}